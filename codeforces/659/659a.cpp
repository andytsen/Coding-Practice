#include <iostream>
using namespace std;

// andytseng
int abs(int x)
{
    return (x < 0) ? -1 * x : x;
}
int main() 
{
    int n, a, b;
    cin >> n >> a >> b;
    int d  = abs(b) % n;   
    if(b > 0)
    {
        a += d;
    }
    else
    {
        a -= d;
    }
    if(a <= 0)
    {
       a += n; 
    }
    else if(a > n)
    {
        a = abs(n - a);
    }
    cout << a << endl;
    return 0;
}
