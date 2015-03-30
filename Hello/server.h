#include <boost/array.hpp>
#include <boost/bimap.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "mQ.h"
#include <memory>
#include <array>


#define NETWORK_BUFFER_SIZE 4096

typedef boost::bimap<long long, udp::endpoint> ClientList;
typedef ClientList::value_type Client;
typedef std::pair<std::string, long long> ClientMessage;

class Server{
	private:

		// NETWORK MEMBER FUNCTIONS
		boost::asio::io_service io_service;
		udp::socket socket;
		udp::endpoint server_endpoint;
		udp::endpoint remote_endpoint;
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




		void send(const std::string& message, udp::endpoint target_endpoint)
		{
		    socket.send_to(boost::asio::buffer(message), target_endpoint);
		    sentBytes += message.size();
		    sentMessages++;
		}
		
		void handle_receive(const boost::system::error_code&, std::size_t);


		void start_receive()
		{
		    socket.async_receive_from(boost::asio::buffer(recv_buffer), remote_endpoint,
		        boost::bind(&NetworkServer::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
		}


	public:

		// CTOR and DTOR
		Server(unsigned short local_port);
		~Server();

		

		void run_service()
		{
		    start_receive();
		    while (!io_service.stopped()){
		        try {
		            io_service.run();
		        } catch( const std::exception& e ) {
		            LogMessage::error("Server network exception: ",e.what());
		        }
		        catch(...) {
		            LogMessage::error("Unknown exception in server network thread");
		        }
		    }
		    LogMessage::Debug("Server network thread stopped");
		};




		void SendToClient(const std::string& message, unsigned long long clientID) 
		{
		    try {
		        send(message, clients.left.at(clientID));
		    }
		    catch (std::out_of_range) {
		        LogMessage::error("Unknown client ID");
		    }
		}



		unsigned long long get_client_id(udp::endpoint endpoint)
		{
		    unsigned long long cit = clients.right.find(endpoint);
		    if (cit != clients.right.end())
		        return (*cit).second;

		    nextClientID++;
		    clients.insert(Client(nextClientID, endpoint));
		    return nextClientID;
		}


		
		void SendToAllExcept(const std::string& message, unsigned long long clientID){
			typedef ClientList::const_iterator it;
			for (it iter = clients.begin(); iend = clients.end(); iter != iend; iter++){
				if (iter->left != clientID)
					SendToClient(message,  iter->left);
			}
		}


		void SendToAll(const std::string& message){
			typedef ClientList::const_iterator it;
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