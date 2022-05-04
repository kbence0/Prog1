//g++ drill.cpp -o main
#include "../std_lib_facilities.h"

struct Item
{
	string name;
	int iid;
	double value;

	Item(string alias, int iden, double val)
	{
		name = alias;
		iid = iden;
		value = val;
	};
};

class rmn
{
	string st;
public:
	rmn(const string& stri):st{stri}{};
	bool operator()(const Item& itm) const{return itm.name == st;};
};

/* VÉDÉS
struct cmpName
{
	bool operator()(const Item& it, const Item& itv) const {return it.name < itv.name;};
};
*/
class rmid
{
	int v;
public:
	rmid(const int& val):v{val}{};
	bool operator()(const Item& itm) const{return itm.iid == v;};
};


int main()
{
	cout << "vector" << endl;

	vector<Item> vi;
	ifstream input("data.txt");

	while(1)
	{
		string name;
		int id;
		double val;
		input >> name;
		//cout << name << " ";
		input >> id;
		//cout << id << " ";
		input >> val;
		//cout << val << endl;
		if (input.eof())
		{
			break;
		}
		vi.push_back(Item(name,id,val));
	}

	cout << endl << "------------" << endl << endl;

	cout << "Read from file:" << endl;
	for (Item i:vi)
	{
		cout << i.name << " " << i.iid << " " << i.value << " " << endl;
	}

	cout << endl << "------------" << endl << endl;
	cout << "Sort by name:" << endl;
	
	sort(vi.begin(),vi.end(),[](const Item& it, const Item& itv)
	{
		return it.name < itv.name;
	});
	
	//VÉDÉS
	//sort(vi.begin(),vi.end(),cmpName());
	
	for (Item i:vi)
	{
		cout << i.name << " " << i.iid << " " << i.value << " " << endl;
	}

	cout << endl << "------------" << endl << endl;
	cout << "Sort by iid:" << endl;

	sort(vi.begin(),vi.end(),[](const Item& it, const Item& itv)
	{
		return it.iid < itv.iid;
	});

	for (Item i:vi)
	{
		cout << i.name << " " << i.iid << " " << i.value << " " << endl;
	}

	cout << endl << "------------" << endl << endl;
	cout << "Sort by value:" << endl;

	sort(vi.begin(),vi.end(),[](const Item& it, const Item& itv)
	{
		return it.value > itv.value;
	});

	for (Item i:vi)
	{
		cout << i.name << " " << i.iid << " " << i.value << " " << endl;
	}

	cout << endl << "------------" << endl << endl;
	cout << "Insert Item:" << endl;

	vi.push_back(Item("horse shoe",99,12.34));
	vi.push_back(Item("Canon S400", 9988,499.95));
	/*
	sort(vi.begin(),vi.end(),[](const Item& it, const Item& itv)
	{
		return it.value > itv.value;
	});
	*/
	
	
	for (Item i:vi)
	{
		cout << i.name << " " << i.iid << " " << i.value << " " << endl;
	}

	cout << endl << "------------" << endl << endl;
	cout << "Remove Item Name [horse shoe]:" << endl;

	vi.erase(find_if(vi.begin(),vi.end(),rmn("horse shoe")));
	//vi.erase(find_if(vi.begin(),vi.end(),rmn("Canon S400")));

	for (Item i:vi)
	{
		cout << i.name << " " << i.iid << " " << i.value << " " << endl;
	}

	cout << endl << "------------" << endl << endl;
	cout << "Remove Item ID [9988 (Canon S400)]:" << endl;

	//vi.erase(find_if(vi.begin(),vi.end(),rmid(99)));
	vi.erase(find_if(vi.begin(),vi.end(),rmid(9988)));

	for (Item i:vi)
	{
		cout << i.name << " " << i.iid << " " << i.value << " " << endl;
	}
	return 0;
}
