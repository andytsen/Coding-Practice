#include <iostream>
using namespace std;

int main()
{
    int i = 9;
    int& a = i; // int& on the LEFT expects a LEFT value 
    int* b = &a; 
    int*& c = b; 

    cout << "i: " << i << endl;
    cout << "a: " << a << endl;
    cout << "b: " << *b << endl;
    cout << "c: " << *c << endl;
    a++;
    cout << "i after a++: " << i << endl;
    cout << "a after a++: " << a << endl;
    cout << "b after a++: " << *b << endl;
    cout << "c after a++: " << *c << endl;

    return 0;
}
