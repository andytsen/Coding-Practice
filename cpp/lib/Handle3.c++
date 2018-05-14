#include <iostream>
#include "Handle3.h"

using namespace std;

struct Foo {
    Foo() {}
    ~Foo() {}
};

int main() {
    Handle<Foo> f(new Foo);
    Handle<Foo> y = move(f);
    return 0;
}
