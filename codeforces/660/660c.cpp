#include <iostream>
using namespace std;

int main()
{
    // read
    int n, k;
    int a[n];
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
       cin >> a[i]; 
    }

    // solve
    int left = 0;
    int right = 0;
    int zeroes = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            zeroes++;
        }
        if(zeroes >= k)
        {
        }
    }

    return 0;
}
