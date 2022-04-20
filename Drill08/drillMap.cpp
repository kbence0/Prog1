//g++ drillMap.cpp -o main
#include "../std_lib_facilities.h"

void insert(map<string,int>& mp,int amount=1)
{
	string name;
	int value;
    for (int i = 0; i < amount; ++i)
    {
    	cin >> name >> value;
    	mp.insert(make_pair(name,value));
    }
}

int main()
{
	map<string,int> msi;
	msi["first"] = 10;
	msi["second"] = 20;
	msi["third"] = 30;
	msi["fourth"] = 40;
	msi["fifth"] = 50;
	msi["sixth"] = 60;
	msi["seventh"] = 70;
	msi["eighth"] = 80;
	msi["ninth"] = 90;
	msi["tenth"] = 100;

	for (auto itr = msi.begin(); itr != msi.end(); ++itr) {
        cout << itr->first << ' ' << itr->second
             << '\n';
    }

    msi.clear();

    cout << endl << "Input Data:" << endl;
    insert(msi,2);


    cout << endl << "Map Content:" << endl;
    for (auto itr = msi.begin(); itr != msi.end(); ++itr) {
        cout << itr->first << ' ' << itr->second
             << '\n';
    }

    cout << endl << "Sum of values: ";
    int sum = 0;
    for (auto itr = msi.begin(); itr != msi.end(); ++itr) {
        sum+=itr->second;
    }
    cout << sum << endl;

    map<int,string> mis;

    for (auto itr = msi.begin(); itr != msi.end(); ++itr) {
        mis.insert(make_pair(itr->second,itr->first));
    }

    cout << "mis Content:" << endl;
    for (auto itr = mis.begin(); itr != mis.end(); ++itr) {
        cout << itr->first << ' ' << itr->second
             << '\n';
    }

	return 0;
}