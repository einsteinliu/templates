#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef int(*Func)(void*);

template<typename T>
class ClassWithFuncPtr
{
public:
	ClassWithFuncPtr();
	~ClassWithFuncPtr();
	void setObj(T obj);
	void printMe();
	int getLength();
	void registerFunc(string functionName,const Func funcFromOutside);
	Func myPrint;
	Func myLength;
private:
	T mStr;
	vector<T> allStr;
};

template<typename T>
ClassWithFuncPtr<T>::ClassWithFuncPtr()
{
}

template<typename T>
ClassWithFuncPtr<T>::~ClassWithFuncPtr()
{
}

template<typename T>
void ClassWithFuncPtr<T>::registerFunc(string functionName, const Func funcFromOutside)
{
	if ("print" == functionName)
		myPrint = funcFromOutside;
	else if ("length" == functionName)
		myLength = funcFromOutside;
}

template<typename T>
void ClassWithFuncPtr<T>::printMe()
{
	(*myPrint)((void*)&mStr);
	return;
}


template<typename T>
int ClassWithFuncPtr<T>::getLength()
{
	return (*myLength)((void*)&mStr);
}

template<typename T>
void ClassWithFuncPtr<T>::setObj(T obj)
{
	mStr = obj;
}