#include <iostream>

int* g(int*&, int*, int&, int);

void f()
{
    int a = 4;
    int& j = a;
    a++;
    std::cout << a << " " << j << std::endl;

    int* b = &a; // x
    std::cout << *b << " " << ++(*b) << " " <<  a << " " << std::endl; 

    int j = 4;

    
     
}

/*
int* g(int*& a, int* b, int& c, int d)
{
    
}
*/

int main()
{

    f();
    
    return 0;
}
