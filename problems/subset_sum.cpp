// Subset sum problem: Given a integer tgt, and an array of sorted ints,
// return a subset of the array that sums to tgt.

#include <iostream>
#include <vector>

using namespace std;

// recursive
/*
void search(vector<int>& nums, vector<int>& res, int index, int tgt) {
    if(tgt == 0) {
        for(int i : res)
            cout << i << " ";
        cout << endl;
        return;
    }
    if(index == nums.size()) {
        return;
    }

    search(nums, res, index + 1, tgt);
    if(index == 0 || nums[index - 1] != nums[index]) {
        res.push_back(nums[index]);
        search(nums, res, index + 1, tgt - nums[index]);
        res.erase(res.end()-1);
    }
}
*/

bool subsetSum(vector<int>& nums, int tgt) {
    vector<vector<bool>> dp(nums.size()+1, vector<bool>(tgt+1, false));
    for(int i = 0; i <= tgt; i++) {
        dp[0][i] = false;
    }
    for(int i = 0; i <= nums.size(); i++) {
        dp[i][0] = true;
    }
    for(int i = 1; i < nums.size(); i++) {
        for(int j = 1; j < tgt; j++) {
           dp[i][j] = dp[i-1][j];
           if(dp[i][j] == false && j >= nums[i-1]) {
               dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
           }
        }
    }
    for(int i = 0; i < nums.size()+1; i++) {
        for(int j = 0; j < tgt+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[nums.size()][tgt];
}

int main() {
    vector<int> nums = {1,2,7,6,8};
    subsetSum(nums, 9);
    return 0;
}
