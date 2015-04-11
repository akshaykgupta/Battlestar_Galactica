#include "networkManager.h"

NetworkManager::~NetworkManager(){
	io_service.stop();
	service_thread.join();
}

void NetworkManager::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred){
	if (!error)
	{
	   	ClientMessage message = ClientMessage(std::string(recv_buffer.data(), recv_buffer.data() + bytes_transferred),  get_client_id(remote_endpoint));
		if (!message.first.empty())
		{
			messages.push(message);
			cout << message.first <<"\n";
		}
		else
		{
			cout << "empty message\n";
		}
	    receivedBytes += bytes_transferred;
	    receivedMessages++;
	}
	else
	{
		cout << "error!" <<"\n";
	}

	start_receive();
}