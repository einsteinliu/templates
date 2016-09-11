#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include "HDTimer.h"
using namespace std;

atomic<int> v{ 0 };


int testThread2()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "slept for 1 seconds\n";
	return 2;
}

int testThread1()
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	cout << "slept for 3 second\n";
	return 1;
}

void main()
{	
	//thread newThread(testThread);
	//newThread.join();	
	Timer timer;
	timer.Start();
	
	/*async(launch::async, testThread1);
	async(launch::async, testThread2);*/
	
	/*std::future<void> fuRes1 = async(launch::async,testThread1);
	std::future<void> fuRes2 = async(launch::async, testThread2);*/

	auto fuRes1 = async(launch::async, testThread1);
	auto fuRes2 = async(launch::async, testThread2);
	
	cout << "fures1 valid:" << fuRes1.valid() << endl;
	cout << fuRes1.get() << endl;
	cout << "fures1 valid:" << fuRes1.valid() << endl;
	//fuRes2.get();

	cout << fuRes2.get() << endl;
	//cout << fuRes1.get() << " " << fuRes2.get() << endl;
	timer.Stop();
	cout << timer.Elapsed() << endl;
	int h;
	cin >> h;
	return;
}