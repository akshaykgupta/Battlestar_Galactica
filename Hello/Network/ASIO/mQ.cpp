#include "mQ.h"


template<typename T>	
void message_queue::push(T value){
		boost::mutex::scoped_lock lock(mutex);
		queue.push(value);
	}

template<typename T>
T message_queue::pop()
{
	boost::mutex::scoped_lock lock(mutex);
	T value;
	std::swap(value, queue.front());
	queue.pop();
	return value;	
}




bool message_queue::empty(){
	boost::mutex::scoped_lock lock(mutex);
	return queue.empty();
}


