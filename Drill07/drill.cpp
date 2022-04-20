#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

using namespace std;

template <typename Iterator1, typename Iterator2>
void Write(Iterator1 array_begin, Iterator2 array_end)
{
   for (auto i = array_begin; i!=array_end; ++i)
   {
       cout << *i <<" ";
   }
   cout << endl;
}

template<typename Iterator1, typename Iterator2>
Iterator2 Copy(Iterator1 f1, Iterator1 e1, Iterator2 f2)
{
    for (Iterator1 i=f1; i!=e1; ++i)
    {
        *f2++=*i;
    }
    return f2;
}

template<typename T>
void Add(T& array, int amount)
{
    for (auto& i:array)
    {
        i+=amount;
    }
}

int main()
{
    array<int,10> aint = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vint = {0,1,2,3,4,5,6,7,8,9};
    list<int> lint = {0,1,2,3,4,5,6,7,8,9};

    array<int,10> aint1 = aint;
    vector<int> vint1 = vint;
    list<int> lint1 = lint;
    
    cout << "Array: ";
    Write(aint.begin(),aint.end());
    cout << "Vector: ";
    Write(vint.begin(),vint.end());
    cout << "List: ";
    Write(lint.begin(),lint.end());
    cout << endl;
  
    Add(aint,2);
    Add(vint,3);
    Add(lint,5);

    cout << "Array: ";
    Write(aint.begin(),aint.end());
    cout << "Vector: ";
    Write(vint.begin(),vint.end());
    cout << "List: ";
    Write(lint.begin(),lint.end());
    cout << endl;

    Copy(aint.begin(),aint.end(),vint.begin());

    vector<int>::iterator ivint = find(vint.begin(),vint.end(),3);
    if (ivint != vint.end())
    {
        cout << "A 3-as a(z) " << distance(vint.begin(),ivint) << " helyen van\n";
    }
    else cout << "Nincs 3-as" << endl;

    list<int>::iterator ilint = find(lint.begin(),lint.end(),27);
    if (ilint != lint.end())
    {
        cout << "A 27 a(z) " << distance(lint.begin(),ilint) << " helyen van";
    }
    else cout << "Nincs 27-es" << endl;
}