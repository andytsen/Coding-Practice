#include <iostream>
#include <map>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    map<long long,int> mp;  
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        long long ai;
        cin >> ai;    
        for(long long k = 2L; k <= 4294967296LL; k *= 2)
        {
            ans += mp[k - ai]; 
        }
        mp[ai]++;
    }
    cout << ans << endl;
    return 0;
}
