#include <iostream>
#include <vector>

using namespace std;

struct A {
    A () {
        cout << "A() ";
    }
    A (const A&) {
        cout << "A(const A&) ";
    }
};

struct B : A {
    B () {
        cout << "B() ";
    }
    B (const B&) {
        cout << "B(const B&) ";
    }
};

struct H {
    H(A*) {
        cout << "H(A*) ";
    }
    H(const H&) {
        cout << "H(const X&) ";
    }
};

int main() {
    vector<A> a(2, B());
    cout << endl;
    vector<A*> b(2, new B());
    cout << endl;
    vector<H> x(2, new B());
    cout << endl;
    return 0;
}
