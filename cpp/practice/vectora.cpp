#include <iostream>
#include "vector4.h"
#include <vector>

using namespace std;

struct B {
    B () {
        cout << "A() ";
    }
    B (int) {
        cout << "A(int) ";
    }
    B (const B&) {
        cout << "A(A) ";
    }
    ~B () {
        cout << "~A() ";
    }
    B& operator = (const B&) {
        cout << "=(A) ";
        return *this;
    }
};

int main() {
    B v = 3; // calls A(int)
    my_vector<B> x(2,v);
    my_vector<B> y(2,v);

    cout << endl;
    x = y;
    cout << endl;

    vector<B> a(2,v);
    vector<B> b(2,v);

    cout << endl;
    a = b;
    cout << endl;
    return 0;
}
