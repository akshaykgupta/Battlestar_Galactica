#include <boost/thread/mutex.hpp>
#include <queue>
#include <list>

template <typename T>
class message_queue{
private:
	boost::mutex mutex;
	std::queue<T> queue;

public:

	void push(T value);
	

	T pop();

	bool empty();


};