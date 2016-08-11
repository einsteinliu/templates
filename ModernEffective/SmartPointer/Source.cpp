#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> createnew()
{
	return unique_ptr<int>{new int{4}};
}

shared_ptr<int> createnewShared()
{
	return unique_ptr<int>{new int{ 4 }};
}

struct V
{
	int* v;
	V()
	{
		v = new int[100];
	}
};

void deleteV(V* vPtr)
{
	delete vPtr->v;
}

void main()
{
	unique_ptr<int> p{ new int };
	*p = 3;
	p = createnew();
	//unique_ptr<int> q = p; //wrong, copy is not allowed
	unique_ptr<int> q = move(p);//move
	if (p == nullptr)
		cout << "p is null now\n";
	
	q.release();//delete p
	
	int n = 5;
	unique_ptr<int[]> intArray{ new int[n] };
	for (int i = 0; i < n; i++)
		intArray[i] = i;

	shared_ptr<int> s{ new int{3} };
	shared_ptr<int> v = move(s);
	shared_ptr<int> k = v;
	long count = k.use_count();
	v.reset();
	int kContent = *k;
	
	int normalInt = 5;
	shared_ptr<int> changedPtr = make_shared<int>(5);

	shared_ptr<V> newV{ new V(),deleteV};
	shared_ptr<V> oldV = newV;
	oldV.reset();
	newV.reset();

	cin >> *q;
}