#include <iostream>

using namespace std;

int main() {
    int a[] = {1,2,3};
    cout << sizeof(&a[0]) << endl;
    cout << sizeof(a) << endl;
    return 0;
}
