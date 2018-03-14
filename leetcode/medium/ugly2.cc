// Ugly Number II
// Andy Tseng 3/13/18

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// 3-ptr of what power2, power3, and power5 is.
int nthUglyNum(int n) {
    vector<int> dp(n);
    dp[0] = 1; // the first ugly num is 1
    int p3 = 0;
    int p2 = 0;
    int p5 = 0;
    for(int i = 1; i < n; ++i) {
        dp[i] = min(dp[p3] * 3, min(dp[p2] * 2, dp[p5] * 5));  
        if(dp[i] == dp[p3] * 3) p3++;
        if(dp[i] == dp[p5] * 5) p5++;
        if(dp[i] == dp[p2] * 2) p2++;
    }
    return dp[n-1];
}

int main() {
    int n;
    cin >> n;
    cout << nthUglyNum(n) << endl;
    return 0;
}

