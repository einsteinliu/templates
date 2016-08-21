#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
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