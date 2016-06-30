#include "ClassWithFuncPtr.h"


ClassWithFuncPtr::ClassWithFuncPtr()
{
	mStr = "Hello world";
}

ClassWithFuncPtr::~ClassWithFuncPtr()
{
}

void ClassWithFuncPtr::registerFunc(const Func funcFromOutSide)
{
	theFuncInside = funcFromOutSide;
}

void ClassWithFuncPtr::canBeCalled()
{
	(*theFuncInside)((void*)&mStr);
}

void ClassWithFuncPtr::setObj(string obj)
{
	mStr = obj;
}

