#include <iostream>
using namespace std;

struct A {
    A () {
        cout << "A() ";
    }
    A (const A&) {
        cout << "A(const A&) ";
    }
    A (A&&) {
        cout << "A(A&&) ";
    }
    ~A () {
        cout << "~A() ";
    }
    A& operator = (const A&) {
        cout << "=(const A&) ";
        return *this;
    }
    A& operator = (A&&) {
        cout << "=(A&&) ";
        return *this;
    }
};

A f3 (A& y) {
    return y;
}

int main() {

    A x;
    cout << endl;

    x = f3(x);
    cout << endl;

    return 0;
}
