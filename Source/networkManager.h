#ifndef NETWORK_MANAGER
#define NETWORK_MANAGER
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/chrono.hpp>
#include <ctime>


/* TODO: Include boost sockets, threads, mention library includes and so on.
	Look at helloUDP in the Hello directory ~
*/

/** The header file for network manager. */

#include <tuple>
using namespace std;
typedef  tuple< int,int,int,int > tIP4;

class NetworkManager {
public:
	/** Need a heap/queue of messages/things */
private:
	/** Need stuff here. */
};
#endif