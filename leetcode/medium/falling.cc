// leetcode: https://leetcode.com/problems/minimum-falling-path-sum/description/
// Andy Tseng: art2589


#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool inrange(int n, int j) { return j >= 0 && j < n; }

int findMinFalling(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) dp[0][i] = mat[0][i];

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int res = dp[i-1][j];
            dp[i][j] += mat[i][j];
            if(inrange(n,j - 1)) {
                res = min(res, dp[i-1][j-1]);
            }
            if(inrange(n,j + 1)) {
                res = min(res, dp[i-1][j+1]);
            }
            dp[i][j] += res;
        }
    }

    int res = dp[n-1][0];
    for(int i = 1; i < n; ++i) {
        res = min(res, dp[n-1][1]);
    }
    return res;
}


int main() {
    vector<vector<int>> sq;
    sq.push_back({1,3,7});
    sq.push_back({8,9,4});
    sq.push_back({15,2,10});
    cout << findMinFalling(sq) << " = 9 " << endl;

    vector<vector<int>> sq1;
    sq1.push_back({7,4,2});
    sq1.push_back({10,13,18});
    sq1.push_back({1,3,2});
    cout << findMinFalling(sq1) << " = 15 " << endl;



}
