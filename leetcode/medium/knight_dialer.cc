// leetcode: https://leetcode.com/problems/knight-dialer/description/
// Andy Tseng


#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int dial(int n) {
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(10, 0));

    // you can start on any number on the dialpad
    for(int i = 0; i < 10; ++i) dp[0][i] = 1;
    int mod = pow(10,9) + 7;

    for(int i = 1; i < n; ++i) {
        dp[i][0] = (dp[i-1][6] + dp[i-1][4]) % mod; 
        dp[i][1] = (dp[i-1][6] + dp[i-1][8]) % mod;
        dp[i][2] = (dp[i-1][7] + dp[i-1][9]) % mod;
        dp[i][3] = (dp[i-1][4] + dp[i-1][8]) % mod;
        dp[i][4] = (dp[i-1][3] + dp[i-1][0] + dp[i-1][9]) % mod;
        dp[i][6] = (dp[i-1][1] + dp[i-1][7] + dp[i-1][0]) % mod;
        dp[i][7] = (dp[i-1][2] + dp[i-1][6]) % mod;
        dp[i][8] = (dp[i-1][1] + dp[i-1][3]) % mod;
        dp[i][9] = (dp[i-1][2] + dp[i-1][4]) % mod;
    } 

    int res = 0;
    for(int i = 0; i < 10; ++i) {
        res += (dp[n-1][i] % mod);
    }
    return res;

}


int main() {
    cout << dial(1) <<  " = 10" << endl;
    cout << dial(2) <<  " = 20" << endl;
    cout << dial(3) <<  " = 46" << endl;
    cout << dial(10) <<  " = 14912" << endl;
}






// testing ~
