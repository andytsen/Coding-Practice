#include <iostream>
#include <cassert>

using namespace std;

struct A {
    static int c;
    A() {c++;}
    ~A() {--c;}
};

static int d;

struct B {
    B() {d++;}
    ~B() {d--;}
};

struct C {
    C() {d++;}
    ~C() {d--;}
};

int A::c = 0;

int main() {

    {
        A p;
        assert(A::c == 1);
    }
    assert(A::c == 0);

    {
        B p;
        C q;
        assert(d == 2);
    }
    assert(d == 0);

    cout << "Finish." << endl;
    return 0;
}
