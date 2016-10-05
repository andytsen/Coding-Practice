///////////////////////////////////////////////////
// Review for OOP with const int and other stuff //
///////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
    /*
    int a[3] = {3,4,6};
    const int* b = a;
    b++;
    a[0]++;
    cout << *b << " " << a[1] << endl;

    int a2[4] = {5,1,3,4};
    const int* b2 = a2;
    b2++;
    //cout << (++b2[2]) << " " << a2[1] << endl;

    int a3[3] = {3, 4, 2};
    int* const b3 = a3;
    cout << ++b3[1] << " " << ++a3[0] << endl;
    */

    int a[3] = {3,4,6};
    const int* b = a;
    b++;
    a[0]++;
    cout << *b << " " << a[1] << endl;

    char a2[4] = {'a', 'm', 'b', 'e'};
    const char* b2 = a2;
    b2++;
    //cout << ++b2[1] << " " << a2[1] << endl; // error

    double a3[5] = {1.0, 2.1, 3.45, 5.1, 6.5};
    double* const b3 = a3;
    //b3++; // error
    b3[0] = 6.1;
    cout << b3[1] << " " << a3[1] << endl;
    return 0;
}
