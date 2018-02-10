// -------------
// UniquePtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // move

#include "unique.cpp"

using namespace std;

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

int main () {
    cout << "UniquePtr.c++" << endl;

    {
//        my_unique_ptr<A> y = new A;
        my_unique_ptr<A> x(new A);
        assert(A::c == 1);
    }
    cout << A::c << endl;
    assert(A::c == 0);

    {
        my_unique_ptr<A> x(new A);
        my_unique_ptr<A> y = move(x);
        assert(A::c == 1);
    }
    assert(A::c == 0);

    {
        my_unique_ptr<A> x(new A);
        my_unique_ptr<A> y(new A);
        assert(A::c == 2);
        x = move(y);
        assert(A::c == 1);
        assert(!y);
    }
    assert(A::c == 0);

    cout << "Done." << endl;
    return 0;
}
