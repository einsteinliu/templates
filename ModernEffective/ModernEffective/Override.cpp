#include <iostream>

using namespace std;

class  Base
{
public:
	Base() {};
	 ~Base() {};
	 virtual void func() { cout << "I am base class\n"; };
};

class Derived : public Base
{
public:
	Derived() {};
	~Derived() {};
	void func() override { Base::func(); cout << "I am derived class\n"; };
};


void main()
{
	Derived derived;
	derived.func();
	int k;
	cin >> k;
}