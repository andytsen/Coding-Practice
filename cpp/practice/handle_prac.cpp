#include <iostream>
#include "Handle1.h"
using namespace std;

struct A {
    A () {
        cout << "A() ";
    }
    A (const A&) {
        cout << "A(A) ";
    }
    ~A () {
        cout << "~A() ";
    }
    A& operator = (const A&) {
        cout << "=(A) ";
        return *this;
    }
    A* clone () const {
        cout << "clone() ";
        return new A(*this);
    }
};


int main() {

    Handle<A> x = new A;
    Handle<A> y (x);
    cout << endl;

    Handle<A> a = new A;
    Handle<A> b = a;
    cout << endl;

    Handle<A> c = new A;
    Handle<A> d = new A;
    cout << endl;
    c = d; // destroys d after swapping with c

    Handle<A> e = new A;
    Handle<A> f = new A;
    cout << "------------------------" << endl;

    f = d;
    c = f;
    cout << "------------------------" << endl;
    cout << endl;

    Handle<A> g = new A;

    return 0;
}
