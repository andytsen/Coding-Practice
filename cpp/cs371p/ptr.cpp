#include <iostream>
using namespace std;

int main() {
    int** a;
    int* b;
    int* c;
    int d = 9;


    b = &d;
    c = b;

    cout << "TEST 1" << endl;
    cout << "======" << endl;
    cout << "b : " << b << endl; 
    cout << "c : " << c << endl; 

    a = &c;
    cout << "TEST 2" << endl;
    cout << "======" << endl;
    cout << "a : " << a << endl;
    cout << "*a : " << *a << endl;
    cout << "c : " << c << endl; 
    cout << "**a : " << **a << endl;

    return 0;
}
