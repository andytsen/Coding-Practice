
#include <iostream>



class foo {


public:
    foo() 
    {
        std::cout << "foo() called\n";
    }

    void func1() 
    {
        std::cout << "foo::func1" << std::endl;
    }

    foo* operator -> () {
        return this;
    }


};

extern foo foo_extern_var;
static foo foo_static_var;

extern foo* foo_extern_ptr;
static foo* foo_static_ptr = new foo();


