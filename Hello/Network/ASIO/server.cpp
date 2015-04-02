#include "server.h"

Server::Server(unsigned short local_port){}

Server::~Server(){
	io_service.stop();
	service_thread.join();
}

Server::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred){
	if (!error)
	{
	   	ClientMessage message = ClientMessage(buffer(recv_buffer.data(), recv_buffer.data() + bytes_transferred),  get_client_id(remote_endpoint));

		if (!message.first.empty())
			incomingMessages.push(message);
	    receivedBytes += bytes_transferred;
	    receivedMessages++;
	}
	else
	{
	  //  LogMessage::error("NetworkClient::handle_receive:",error);
	}

	start_receive();
}