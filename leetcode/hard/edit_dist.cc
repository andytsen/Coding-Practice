// edit distance on leetcode
// Andy Tseng 3/14/18

#include <iostream>
#include <string>
#include <vector>
#define rep(i,s,n) for(int i = s; i < n; ++i)
#define min(a,b) ((a < b) ? (a) : (b))

using namespace std; // for convenience

int edit(string w1, string w2) {
    int n = w1.size();
    int m = w2.size();
    vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1,0));
    rep(i,0,m + 1) dp[i][0] = i; 
    rep(j,0,n + 1) dp[0][j] = j; 
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(w1[i-1] == w2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << edit("horse", "ros") << endl;
    return 0;
}
