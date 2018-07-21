// Andy Tseng
// http://codeforces.com/problemset/problem/961/B

#include <iostream>
#include <vector>
#define max(a,b) (a > b ? (a) : (b))

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> t = vector<int>(n,0);
    vector<int> a = vector<int>(n,0);
    vector<int> dp = vector<int>(n - k,0);
    for(int i = 0; i < n; ++i) { cin >> a[i]; }
    for(int i = 0; i < n; ++i) { cin >> t[i]; }

    // brute force first!
    // O(n * k)
    int v = -1;
    int start = 0;
    int end = k;

    for(int i = 0; i < k; ++i) { dp[0] += a[i]; }
    int index = 1;
    while(index < n - k + 1) {
        dp[index] = dp[index-1] - a[start] + a[end]; 
        index++;
        end++;
        start++;
    }

    int ind = 0;
    for(int i = 0; i < dp.size(); ++i) { 
        if(t[i] == 0) {
            v = max(v,dp[i]); 
            ind = i;
        }
    }

    for(int i = 0; i < n; ++i) {
        if(i == ind) {
            i += k - 1;
        } else if(t[i] == 1) {
            v += a[i];
        }
    }
    cout << v << " " << ind << endl;

    return 0;

}
