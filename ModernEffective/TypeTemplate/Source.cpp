#include <iostream>
using namespace std;

class Widget
{
public:
	Widget(int i, bool b)
	{
		m_i = i;
		m_b = b;
	}
	Widget(int i, double d)
	{
		m_i = i;
		m_d = d;
	}
	Widget(std::initializer_list<int> il)
	{
		int i = 0;
		for (auto itre = il.begin(); itre != il.end(); itre++,i++)
			m_l[i] = *itre;
	}
private:
	int m_l[256];
	int m_i{ 1 };
	bool m_b{ false };
	double m_d{ 1.0 };
};

template<typename T>
void funcValue(T param)
{
	auto subParam = param;
	decltype(auto) subSubParam = subParam;
}

template<typename T>
void funcRef(T& param)
{
	T subParam;
}

template<typename T>
void funcPoint(T* param)
{
	T subParam;
}

template<typename T>
void funcPointPoint(T** param)
{
	T subParam;
}


void main()
{
	int value = 2;
	int& valueRef = value;
	int* valuePtr = &value;
	int array[] = { 0,1,2 };
	int** mat = new int*[10];
	for (int i = 0; i < 10; i++)
	{
		mat[i] = new int[10];
		for (int j = 0; j < 10; j++)
			mat[i][j] = i*10+j;
	}

	Widget w1(1, false);
	Widget w2(1, 1.2);
	Widget w3{ 1,false };
	Widget w4{ 1,2,3,4 };

	funcPointPoint(mat);

	funcPoint(valuePtr);
	funcPoint(array);
	funcPoint(mat);

	funcRef(value);
	funcRef(valueRef);
	funcRef(valuePtr);
	funcRef(array);
	funcRef(mat);

	funcValue(value);
	funcValue(valueRef);
	funcValue(valuePtr);
	funcValue(array);
	funcValue(mat);

	decltype(array) arraynew;
	arraynew[2] = 2;
}