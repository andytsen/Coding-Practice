// Maximum Repeating/Matching Subarray
// Andy Tseng, 3/15/18

#include <vector>
#include <iostream>

using namespace std;

int find_len(vector<int> A, vector<int> B) {
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    int ans = INT_MIN;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(A[i] == B[j]) { 
                dp[i][j] = 1;
                int pre = 0;
                if((i - 1) >= 0 && (j - 1) >= 0) {
                    pre = dp[i-1][j-1];
                }
                dp[i][j] += pre;
                if(dp[i][j] > ans) { ans = dp[i][j]; }
            }
        }
    }
    return ans;
}

int main() {
}
