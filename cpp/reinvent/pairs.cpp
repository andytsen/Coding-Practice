#include <iostream>

using namespace std;

template <class T1, class T2>
class mypair {
    public:
        mypair() : first(T1()) , second(T2()) {}
        mypair(T1 f, T2 s) : first(f) , second(s) {} 
        ~mypair() {
            first.~T1();
            second.~T2();
        }
        T1 first;
        T2 second;
};

class A {
    public:
        A() { cout << "A() "; }
        A(const A& a) { 
            *this = a;
            cout << "A(a) "; 
        }
        ~A() { cout << "~A() "; }
};

class B {
    public:
        B() { cout << "B() "; }
        B(const B& b) { 
            *this = b;
            cout << "B(b) "; 
        }
        ~B() { cout << "~B() "; }
};

int main() {
    A a;
    B b;
    mypair<A,B> s(a,b);
    pair<int,int> p1(9,80);
    pair<int,int> p2 = p1;
    if(p2.first == p1.first) { cout << "t1 pass" << endl; }
}
