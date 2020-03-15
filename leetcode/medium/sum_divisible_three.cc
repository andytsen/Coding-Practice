// Leetcode 

#include <vector>
#include <iostream>
#define MAX(a,b) ((a > b) ? a : b)

using namespace std;

int sum_divisible_three(vector<int> nums)
{
    vector<int> dp(3,0);
    for (int n : nums)
    {
        vector<int> tmp(dp);
        for (auto x : dp)
        {
            int cur = n + x;
            tmp[cur % 3] = MAX(cur, tmp[cur % 3]);
        }
        dp = tmp;
    }
    return dp[0];
}

int main()
{
    std::cout << sum_divisible_three({3,6,5,1,8}) << std::endl;
    return 0;
}
