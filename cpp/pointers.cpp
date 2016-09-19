#include <iostream>

int* g(int*&, int*, int&, int);

void f()
{
}

/*
int* g(int*& a, int* b, int& c, int d)
{
    
}
*/

int main()
{
    int i = 9;
    int& a = i; // int& on the LEFT expects a LEFT value 
    int* b = &a; 

    
     
    return 0;
}
