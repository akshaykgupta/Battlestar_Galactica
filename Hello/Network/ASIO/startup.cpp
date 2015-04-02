#include "server.h"


int main(){
	cout << "HELLO server" << '\n';

	Server s("10.192.23.65", 3001); //

	cout << "break 1" << '\n';


	//s.run_service();


	cout << "break 2" << '\n';



	s.SendToAll("HELLO");

	cout << "DONE" << '\n';
}