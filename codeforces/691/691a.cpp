#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int t = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a == 0)
            t++;
    }
    if(t == 1 && n != 1)
        cout << "YES" << endl;
    else if(t == 0 && n == 1)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}
