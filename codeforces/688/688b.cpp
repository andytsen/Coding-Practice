#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a; 
    int len = a.length();
    for(int i = len - 1; i >= 0; i--)
    {
        a += (a.at(i));
    }
    cout << a << endl;
    return 0;
}
