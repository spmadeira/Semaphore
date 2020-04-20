// SemaphoreProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include "Semaphore.h"
#include <thread>
#include <chrono>


using namespace std;

list<int> lista;

void add_to_list(Semaphore* semaphore, int id)
{
	semaphore->acquire();
	cout << "Thread " << id << " Adquiriu" << endl;
	for(int i = 0; i < 5; i++)
	{
		lista.push_back(i + 1);
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	cout << "Thread " << id << " Soltou" << endl;
	semaphore->release();
}

int main()
{
	auto semaphore = new Semaphore();

	thread t1(add_to_list, semaphore, 1);
	thread t2(add_to_list, semaphore, 2);
	thread t3(add_to_list, semaphore, 3);
	thread t4(add_to_list, semaphore, 4);
	thread t5(add_to_list, semaphore, 5);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	for(auto num : lista)
	{
		cout << num << " ";
	}
}