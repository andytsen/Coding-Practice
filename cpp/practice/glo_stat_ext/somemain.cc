#include "lib.h"
#include "calc.h"

int main() 
{

    std::cout << "~~ main ~~" << std::endl;
    foo foo_extern_var;
    foo_extern_var.func1();

    foo foo_local_var;
    foo_local_var.func1();

    foo* foo_extern_ptr = new foo();
    foo_extern_ptr->func1();

    foo_static_ptr->func1();
    return 0;
}
