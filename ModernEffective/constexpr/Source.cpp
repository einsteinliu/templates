#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class busy
{
public:
	double compute(int a, int b)
	{
		lock_guard<mutex> guard(m);
		cout << a + b <<" "<< curr << endl;
		curr += 1.0;
		return a*curr + b;
	}
private:
    double curr = 3.0;
	mutable mutex m;
};

busy bus;

void thread1()
{
	for (int i = 0; i < 10; i++)
		bus.compute(1, 0);
}
void thread2()
{
	for (int i = 0; i < 10; i++)
		bus.compute(1, 1);
}
void main()
{
	thread t1(thread1);
	thread2();
	t1.join();
	int k;
	cin >> k;
}