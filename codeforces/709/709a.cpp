#include <iostream>
using namespace std;

int main() 
{
    long long n,b,d;
    long long total = 0LL;
    cin >> n >> b >> d;
    int cnt = 0;
    for(long long i = 0L; i < n; i++)
    {
        long long a;
        cin >> a;
        if(a > b)
            continue;
        total += a;
        if(total > d)
        {
            total = 0;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
