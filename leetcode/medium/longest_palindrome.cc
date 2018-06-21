// longest palindrome subsequence of string s
// 516 on Leetcode
// Andy Tseng

#include <iostream> // debugging
#include <string>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n,0));
    for(int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for(int j = i+1; j < n; ++j) {
            if(s[i] == s[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    cout << longestPalindromeSubseq("bbab") << endl;
    return 0;
}

