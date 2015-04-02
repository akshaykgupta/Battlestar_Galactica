#include <boost/array.hpp>
#include <boost/bimap.hpp>
#include <boost/asio.hpp>
#include "boost/lexical_cast.hpp"
#include <boost/thread.hpp>
#include "mQ.h"
#include <memory>
#include <array>


#define NETWORK_BUFFER_SIZE 4096

typedef boost::bimap<long long, boost::asio::ip::udp::endpoint> ClientList;
typedef ClientList::value_type Client;
typedef std::pair<std::string, long long> ClientMessage;

using namespace std;
using boost::asio::ip::udp;

class Server{
	private:

		// NETWORK MEMBER FUNCTIONS
		boost::asio::io_service io_service;
		boost::asio::ip::udp::socket socket;
		boost::asio::ip::udp::endpoint server_endpoint;
		boost::asio::ip::udp::endpoint remote_endpoint;
		boost::thread service_thread;


		std::array<char, NETWORK_BUFFER_SIZE> recv_buffer;  // statically allocated container class used as a buffer for receiving data

		// SERVER machinery
		message_queue<std::string> messages;
		unsigned long long nextClientID;
		ClientList clients;

		// DATA
		unsigned long long receivedMessages;
		unsigned long long receivedBytes;
		unsigned long long sentMessages;
		unsigned long long sentBytes;




		void send(const std::string& message, boost::asio::ip::udp::endpoint target_endpoint)
		{
			cout << target_endpoint <<"\n";
		    socket.send_to(boost::asio::buffer(message), target_endpoint);
			cout << "hi\n";
		    sentBytes += message.size();
		    sentMessages++;
		}
		
		void handle_receive(const boost::system::error_code&, std::size_t);


		void start_receive()
		{
		    socket.async_receive_from(boost::asio::buffer(recv_buffer), remote_endpoint,
		        boost::bind(&Server::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
		}


	public:

		// CTOR and DTOR
		Server(string IP, unsigned short local_port) : socket(io_service, udp::endpoint(udp::v4(), local_port))
		{
			boost::asio::ip::udp::resolver resolver(io_service);
			boost::asio::ip::udp::resolver::query query(IP, boost::lexical_cast< string >(local_port));
			boost::asio::ip::udp::resolver::iterator iterator = resolver.resolve(query);
			remote_endpoint = *iterator;
			get_client_id(remote_endpoint);
		}
		~Server();

		

		void run_service()
		{
		    start_receive();
		    while (!io_service.stopped()){
		        try {
		            io_service.run();
		        } catch( const std::exception& e ) {
		            //LogMessage::error("Server network exception: ",e.what());
		        }
		        catch(...) {
		            //LogMessage::error("Unknown exception in server network thread");
		        }
		    }
		    //LogMessage::Debug("Server network thread stopped");
		};




		void SendToClient(const std::string& message, unsigned long long clientID) 
		{
		    try {
		        send(message, clients.left.at(clientID));
		    }
		    catch (std::out_of_range) {
		        //LogMessage::error("Unknown client ID");
		    }
		}



		unsigned long long get_client_id(boost::asio::ip::udp::endpoint endpoint)
		{
		    auto cit = clients.right.find(endpoint);
		    if (cit != clients.right.end())
		        return (*cit).second;

		    nextClientID++;
		    clients.insert(Client(nextClientID, endpoint));
		    return nextClientID;
		}

		
		void SendToAllExcept(const std::string& message, unsigned long long clientID){
			typedef ClientList::const_iterator it;
			for (it iter = clients.begin(), iend = clients.end(); iter != iend; iter++){
				if (iter->left != clientID)
					SendToClient(message,  iter->left);
			}
		}


		void SendToAll(const std::string& message){
			typedef ClientList::const_iterator it;
			cout << "hi\n";
			for(it iter = clients.begin(), iend = clients.end();  iter != iend; ++iter ){
				SendToClient(message,iter->left);
			}
		 }


		// STAT QUERIES
		unsigned long long GetStatReceivedMessages() {return receivedMessages;}
		unsigned long long GetStatReceivedBytes()	   {return receivedBytes;}
		unsigned long long GetStatSentMessages()     {return sentMessages;}
		unsigned long long GetStatSentBytes()        {return sentBytes;}

};