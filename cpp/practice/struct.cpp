#include <iostream>

using namespace std;

struct A {
    A (int) {
        cout << "A(int) ";}
    A (const A&) {
        cout << "A(const A&) ";}
    A& operator = (const A&) {
        cout << "=(const A&) ";
        return *this;}
    A& operator = (A&&) {
        cout << "A(A&&)";
        return *this;
    }
};

int main() {
    A x = 2;
    cout << endl;

    x = 2;      // this line only
    cout << endl;

    const A& a = 2;
    cout << endl;

    const A& b(2);
    cout << endl;

    const A& d = b;
    cout << endl;

    A c = b;
    cout << endl;

    return 0;}
