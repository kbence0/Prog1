//g++ drill.cpp -o main
#include "std_lib_facilities.h"

//1.
template <typename T> 
struct S 
{
	T val;
	
	int num;
	char ch;
	double dnum;
	string tx;
	vector<int> vctr;
	
	//2. 
	S()
	{
	num = 10;
	ch = 'c';
	dnum = 3.14;
	tx = "Text";
	
	for(int i = 1; i<= 5; i++)
	{vctr.push_back(i);}
	};
	
};

int main()
{
	//3.
	S<int> i;
	S<char> c;
	S<double> d;
	S<string> s;
	S<vector<int>> v;
	
	//4.
	cout << i.num << endl;
	cout << c.ch << endl;
	cout << d.dnum << endl;
	cout << s.tx << endl;
	
	/*
	for(int i: v)
   	cout << i << ' ';
	*/
	
	return 0;
};
