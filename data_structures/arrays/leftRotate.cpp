#include <iostream>
using namespace std;


int main() 
{
    int n, d;
    cin >> n >> d;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        int di = i - d; 
        if(di < 0)
        {
            di = n + di;
        }
        b[di] = a[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
