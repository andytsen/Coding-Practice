#include <iostream>

using namespace std;

struct A {
    A () {
        cout << "A() ";}

    A (const A& rhs) {
        cout << "A(const A&) ";
    }

    A (A&&) {
        cout << "A(A&&) ";
    }

    A& operator = (const A&) {
        cout << "=(const A&) ";
        return *this;
    }

    A& operator = (A&&) {
        cout << "=(A&&) ";
        return *this;
    }

    ~A() {
        cout << "~A() ";
    }
};
