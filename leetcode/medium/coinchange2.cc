// leetcode: https://leetcode.com/problems/coin-change-2/
// Andy Tseng


// [1,2,5], amount = 5
// output how many combinations there are
// -> 5 = 5
//      = 1 + 1 + 1 + 2
//      = 1 + 2 + 2
//      = 1 + 1 + 1 + 1 + 1


#include <vector>
#include <iostream>

using namespace std;

int coinChange2(vector<int>& coins, int amount) {
    vector<int> dp = vector<int>(amount+1, 0);
    dp[0] = 1; // base case
    for(int c = 0; c < coins.size(); ++c) {
        for(int j = coins[c]; j <= amount; ++j) {
            dp[j] += dp[j - coins[c]];
        }
    }
    return dp[amount];
}

int main() {
    vector<int> v = {1,2,5};
    cout << coinChange2(v, 5) << " = 4" << endl;
    return 0;
}

