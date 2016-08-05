#include <iostream>
using namespace std;

int main() {
    int m,n;
    cin >> m >> n;
    
    int a[5];
    for(int i = 0; i < 5; i++)
    {
        a[i] = n/5;
    }
    
    if(n % 5 != 0)
    {
        for(int i = 1; i <= (n % 5); i++)
        {
            a[4 - i] += 1;
        }
    }
    long long total = 0L;
    for(int i = 0; i < 5; i++)
    {
        total += a[i]; 
    }
    total *= (m/5); 
    for(int i = 0; i < m % 5; i++)
    {
        total += a[i];
    } 
    cout << total << endl;
    return 0;
}
