#include "server.h"


int main(){
	cout << "HELLO server" << '\n';

	Server s("10.192.31.236", 3001); //

	cout << "break 1" << '\n';


	//s.run_service();


	cout << "break 2" << '\n';

	
	int i = 20;
	while (true)
		s.SendToAll("HELLO");

	cout << "DONE" << '\n';
}