#include <iostream>

using namespace std;

class Mudkip {
    public:
        Mudkip() {}
        void foo() {
            cout << "this addr: " << this << endl;
        }
};

int main() {

    Mudkip* m = new Mudkip();
    m->foo();
    Mudkip* a;
    a->foo();
    cout << "m addr: " << &m << endl;
    cout << "a addr: " << &a << endl;
    delete m;


    return 0;
}

