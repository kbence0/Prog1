//g++ drill.cpp -o main
#include "../std_lib_facilities.h"

template <typename T>
struct S {

    S(T x) : val(x) {}
    S& operator=(const T&);

    T& get();
    //const T& get() const;

private:
    T val;
};

template <typename T> 
T& S<T>::get()
{
	return val;
}

/*
template <typename T> 
const T& S<T>::get() const
{
	return val;
}
*/

template<class T> istream& operator>>(istream& is, S<T>& ss)
{
	T v;
	cin >> v;
	if (!is) return is;
	ss = v;
	return is;
}

template <typename T>
void read_val(T& v)
{
	cin >> v;
}

template <typename T>
S<T>& S<T>::operator=(const T& x)
{
	val = x;
	return *this;
}

int main() {

    S<int> sint(5);
    S<double> sdouble(3.14);
    S<char> schar('A');
    S<string> sstring("drill");
    S<vector<int>> vctr = vector <int>{1, 2, 3, 4, 5};

    cout << sint.get() << endl;
    cout << sdouble.get() << endl;
    cout << schar.get() << endl;
    cout << sstring.get() << endl << endl;


    cout << "Vector elements: " << endl << endl;
    for(int i=0; i < vctr.get().size(); i++)
    {
    	cout << vctr.get()[i] << endl;
    }

    cout << endl << "Change the values:" << endl;

    cout << "Intiger: ";
    read_val(sint);
    cout << "Double: ";
    read_val(sdouble);
    cout << "Charater: ";
    read_val(schar);
    cout << "Text: ";
    read_val(sstring);

    cout << endl;
    cout << sint.get() << endl;
    cout << sdouble.get() << endl;
    cout << schar.get() << endl;
    cout << sstring.get() << endl;

    return 0;
}