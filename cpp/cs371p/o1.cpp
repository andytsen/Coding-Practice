#include <iostream>

using namespace std;

class A {
    protected:
        int _x;
    public:
        A() : _x(0) { cout << "A() " << _x << endl;  }
        A(int& x) : _x(x++) { cout << "A() " << _x << endl;  }
        A(const A& a) : _x(a._x + 1) { cout << "A() " << _x << endl;  }
        int getX() const { return _x;  }

};

class B: public A {
    A a;
    int _x;
    public:
    B(int& x) : _x(x++), A(++x), a(--x) { cout << "B() " << _x << endl;  }
    B(const A& a) : _x(a.getX()), A(a) { cout << "B() " << _x << endl;  }
    B(const B& b) : _x(b._x) { cout << "B() " << _x << endl;  }

};

int main() {
    int x = 3;
    A a = x;
    B b(x);
    B b2 = a;
    B b3 = b;

}
