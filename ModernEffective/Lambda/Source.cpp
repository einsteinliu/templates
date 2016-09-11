#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;


void testBind();
void testClosureMove();

int main()
{
	testClosureMove();
	//testBind();
	return 1;

	auto l = []() {return 4; };
	auto k = l;
	
	int comp = 4;
	vector<int> values{ 1, 2, 3, 4, 5 };
	auto item = find_if(values.begin(), values.end(), 
		[&](int value)
		{//the input argument int const& value is occupied by the STL function
			return value == comp; 
		}
	);
	
	int cap2 = 3;
	int cap3 = 4;
	int cap4 = 5;
	int cap1 = 1;
	auto lam = [&](int arg) 
	{
		cap1 = 5;
		return cap1*arg; 
	};
	int result = lam(6);

	auto lam1 = [&](int arg) {return cap1*arg; };
	auto lam2 = [=](int arg) {return cap1*cap2*arg; };
	//auto lam3 = [](int arg){return cmp1*cmp2*arg; }; //Wrong!
	auto lam4 = [&,cap1](int arg){return cap1*cap2*arg; };
	int r4 = lam4(4);

	auto lam5 = [=](int arg)->double {return cap1*arg; };
	double r5 = lam5(4);


	int n;
	cin >> n;
}

void originalFunc(double a, double b, string c)
{
	cout << a << " " << b << " " << c.c_str() << endl;
}

void testBind()
{
	auto newlyBindedFunc = bind(originalFunc, placeholders::_2, 10.5, placeholders::_1);
	newlyBindedFunc("Hello world",2);
	int k;
	cin >> k;
}

void testClosureMove()
{
	vector<int> originalData{ 1,2,3,4,5,6,7 };

	auto func = bind([](vector<int> &data)
	{
		for (int i = 0; i < data.size(); i++)
		{
			cout << data[i] << " ";
		}
	},
		move(originalData)
		);

	func();
}
