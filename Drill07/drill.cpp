//7. drill
#include "../std_lib_facilities.h"

int main()
{	
	//1.
	int aint [10] = {0,1,2,3,4,5,6,7,8,9};
	//2.
	vector<int> vint;
	//3.
	list<int> lint;
	
	for (int i=0; i<10; i++)
	{
		vint.push_back(i);
		lint.push_back(i);
	}

	//copies
	int aint2 [10];
	vector<int> vint2;
	list<int> lint2;

	//write out
	for (auto i = 0; i < 10; ++i)
	{
        	cout << aint[i] << " ";
        }
	cout << "\n";
	for (auto i = vint.begin(); i != vint.end(); ++i)
	{
        	cout << *i << " ";
        }
        cout << "\n";
        for (auto i = lint.begin(); i != lint.end(); ++i)
        {
        	cout << *i << " ";
	}   
	cout << "\n";

	//5.
	//ELEMENT CHANGE
	//array increase value by 2
	for (auto i = 0; i < 10; ++i)
	{
        	aint[i]=aint[i]+2;
        }
	cout << "\n";
	//vector increase value by 3
	for (auto i = 0; i < 10; ++i)
	{
        	vint[i]=vint[i]+3;
        }
	cout << "\n";
	//list increase value by 5
	
	
	
	
	
	
	
	//write out
	for (auto i = 0; i < 10; ++i)
	{
        	cout << aint[i] << " ";
        }
	cout << "\n";
	for (auto i = vint.begin(); i != vint.end(); ++i)
	{
        	cout << *i << " ";
        }
        cout << "\n";
	for (auto i = lint.begin(); i != lint.end(); ++i)
        {
        	cout << *i << " ";
	}   
	cout << "\n";


	return 0;
}
