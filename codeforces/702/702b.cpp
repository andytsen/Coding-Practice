#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int test = a[i] + a[j];
            if((test & (test - 1)) == 0 && test != 0)
            {
                total++;                
            } 
        }
    }
    cout << total << endl;
    return 0;
}
