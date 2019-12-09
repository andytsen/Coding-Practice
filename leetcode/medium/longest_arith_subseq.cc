#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int longest_arith_subseq(vector<int>& nums)
{
    int res = 2;
    unordered_map<int, unordered_map<int,int>> dp;
    for (int j = 1; j < nums.size(); ++j)
    {
        for(int i = 0; i < j; ++i)
        {
            int g = nums[j] - nums[i];
            if (dp[i].find(g) != dp[i].end())
            {
                dp[j][g] = dp[i][g] + 1;    
            }
            else
            {
                dp[j][g] = 2;
            }
            res = max(res, dp[j][g]);
        }
    }

    return res;
}

int main()
{
    vector<int> v = {9,4,7,2,10};
    cout << longest_arith_subseq(v) << endl;

    vector<int> p = {6,20,1,15,3,10,0,-3};
    cout << longest_arith_subseq(p) << endl;

}
