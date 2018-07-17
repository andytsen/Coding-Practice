
// Longest Increasing Subsequence
// Andy Tseng

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int get_longest(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp = vector<int>(n,1);
    for(int i = 1; i < n; ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    for(int i : dp) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

int main() {
    vector<int> v1 = {1, 3, 5, 4, 7};
    get_longest(v1);
    vector<int> v2 = {3,3,3,3,3};
    get_longest(v2);
    return 0;
}
