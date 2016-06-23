#include <iostream>
#include <stdio.h>
using namespace std;

int main() 
{
    long long a, b, x, y;
    cin >> a >> b >> x >> y;

    long long r1, r2, d;
    if(a % x != 0 && b % y != 0) 
    {
        d = 0L;
    }
    else 
    {
        if(a % x == 0)
        {
            if(b % y == 0)
            {
                if(a/x < b/y)
                {
                    d = b/y;
                }
                else 
                {
                    d = a/x;
                }
            }
            else 
            {
                if(y > b)
                    d = 0;
                else 
                    d = a/x;
            }
        }
        else 
        {
            if(b % y == 0)
            {
                if(x > a)
                    d = 0;
                else 
                    d = b/y;
            }
            else 
                d = 0;
        }
    }
    r1 = d * x;
    r2 = d * y;
    printf("%lld %lld\n", r1, r2);
    return 0;
}
