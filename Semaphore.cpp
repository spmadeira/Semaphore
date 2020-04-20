#include "Semaphore.h"

using namespace std;

Semaphore::Semaphore()
{
	counter = 0;
}

void Semaphore::acquire()
{
	unique_lock<mutex> lock(mtx);
	while (counter < 0)
	{
		cond.wait(lock);
	}
	counter--;
}

void Semaphore::release()
{
	unique_lock<mutex> lock(mtx);
	counter++;
	cond.notify_one();
}

