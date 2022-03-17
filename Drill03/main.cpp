#include "std_lib_facitilies.h"
//chapter 14

//1.
class B1 {
public:
	virtual void vf()
	{
		cout << "Function vf()";
	};
	//5.
	virtual void pvf() = 0;
	void f()
	{
		cout << "Function f()"
	};
}

//2.
class D1 : public B1 {
public:
	void vf() override
	{
		cout << "Derived Function vf()";
	};
	//4.
	void f()
	{
		cout << "Derived Function f()";
	};
}
//6.
class D2 : public D1 {
public:
	void pvf() override
	{
		cout << "D2 Derived Fucntion pvf()";
	};
}
//7.
class B2 {
public:
	virtual void pvf()
	{
		cout << "B2 Fucntion pvf()";
	};
}

class D21 {
public:
	string tx = "text";
	void pvf()
	{
		cout << tx;
	};
}

class D22 {
public:
	int num = 0;
	void pvf()
	{
		cout << num;
	};
}

void f(B2& reference)
{
    reference.pvf();
}

int main()
{
	B1 b1obj;

	b1obj.vf();
	b1obj.f();


	D1 d1obj;

	d1obj.vf();
	d1obj.f();

	//3.
	B1& refclass = new D1;

	refclass.vf();
	refclass.f();



	D2 d2obj;

	d2obj.f();
	d2obj.vf();
	d2obj.pvf();


	D21 d21obj;

	d21obj.pvf();


	D22 d22obj;

	d22obj.pvf();


	f(d21obj);
	f(d22obj);

	return 0;
}