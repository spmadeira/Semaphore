#pragma once
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore
{
private:
	mutex mtx;
	condition_variable cond;
	int counter;

public:
	Semaphore();


	void acquire();
	
	void release();
};
