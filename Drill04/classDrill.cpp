#include "../std_lib_facilities.h"
//g++ classDrill.cpp -o main

//Class definition drill

//1.
struct Person
{
//5.
	Person(){}
	Person(string fn, string sn, int a);

	string fname() const {
		return first_name;
	}
	string sname() const {
		return second_name;
	}
	int old() const {
		return age;
	}
private:
	string first_name;
	string second_name;
	int age;

	//3.
	friend ostream &operator<<(ostream &output, const Person &P)
	{
		output << "Name: " << P.fname() << " " << P.sname() << " Age: " << P.old();
		return output;
	}
	friend istream &operator>>(istream  &input, Person &P)
	{
		//6.
		string fn;
		string sn;
		int a;

        input >> fn >> sn >> a;

        P = Person(fn, sn, a);
        return input;
    }
};

Person::Person(string fn, string sn, int a)
	{

		if (a>0 && a<150)
		{
			age=a;
		}
		else {
			error("Wrong Age");
		}

		string full_name = fn+sn;
		for (char c:full_name)
		{
			switch(c){
				case ';':
				case ':':
				case '"':
				case '\'':
				case '[':
				case ']':
				case '*':
				case '&':
				case '^':
				case '%':
				case '$':
				case '#':
				case '@':
				case '!':
				error("Wrong Name");
				break;
				default: break;
			}
		}

		first_name=fn;
		second_name=sn;
	}

int main()
{
	Person prsn;

	vector<Person> prv;

	for (Person frp;cin>>frp;)
	{
		if (frp == "end")
		{
			break;
		}
		cout<<frp.fname();
		prv.push_back(frp);
	}

	for (Person frp:prv)
	{
		cout << frp << "\n";
	}

/*
	Program stop
	end
	name
	number	
*/
	return 0;
}
