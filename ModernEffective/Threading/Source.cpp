#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include "HDTimer.h"
using namespace std;

atomic<int> v{ 0 };

//volatile int v = 0;

//int v = 0;

void testThread2()
{
	int n = 1000;
	while (n--)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
		//if ((v != 10) && (v != 11))
		cout << v << endl;
	}
}

void testThread1()
{
	int n = 1000;
	while (n--)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));		
		v = 10;
		cout << v << endl;
		v++;
		v--;
	}
}

void main()
{	
	//Timer timer;
	//timer.Start();

	//thread newThread1(testThread1);
	//thread newThread2(testThread2);	
	
	/*async(launch::async, testThread1);
	async(launch::async, testThread2);*/
	
	/*std::future<void> fuRes1 = async(launch::async,testThread1);
	std::future<void> fuRes2 = async(launch::async, testThread2);*/

	auto fuRes1 = async(launch::async, testThread1);
	auto fuRes2 = async(launch::async, testThread2);
	
	//cout << "fures1 valid:" << fuRes1.valid() << endl;
	//cout << fuRes1.get() << endl;
	//cout << "fures1 valid:" << fuRes1.valid() << endl;
	////fuRes2.get();

	//cout << fuRes2.get() << endl;
	////cout << fuRes1.get() << " " << fuRes2.get() << endl;

	//timer.Stop();
	//cout << timer.Elapsed() << endl;

	//newThread1.join();
	//newThread2.join();

	int h;
	cin >> h;
	return;
}