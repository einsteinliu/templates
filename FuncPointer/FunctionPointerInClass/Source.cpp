#include "ClassWithFuncPtr.h"
#include <iostream>

using namespace std;

struct Lena{
	string name;
	int    age;
};

int print(void* ptrToObj)
{
	cout << ((Lena*)ptrToObj)->name << " " << ((Lena*)ptrToObj)->age << endl;
	return 0;
}

int getLength(void* ptrToObj)
{
	return sizeof(*(Lena*)ptrToObj);
}

void main()
{
	ClassWithFuncPtr<Lena> ptr;
	Lena newLena = { "Danqing", 18 };
	ptr.setObj(newLena);
	ptr.registerFunc("print",print);
	ptr.registerFunc("length", getLength);
	ptr.printMe();
	cout << "Length:" << ptr.getLength();
	int k;
	cin >> k;
}