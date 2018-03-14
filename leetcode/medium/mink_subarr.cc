// Min Subarray of sum s
// Andy Tseng, 3/14/18, Stephen Hawking's Death

#include <iostream>
#include <vector>

using namespace std; // convenience

// return the min subarray size that sums to >= integer s
// Implementation: Using dp-esque way using sum of up to ith index and 
// then using it to help with summing the other things.
int minSubArr(vector<int>& nums, int s) {
    if(nums.size() == 0) return 0;
    vector<int> sum(nums.size(), 0);
    sum[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        sum[i] += sum[i-1] + nums[i];
    }
    int prev = 0;
    int ans = INT_MAX;
    if(sum[nums.size() - 1] < s) return 0;
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i; j < nums.size(); ++j) {
            int total = sum[j] - prev;
            if(total >= s) {
                if( (j - i + 1) < ans) {
                    ans = (j - i + 1);
                }
            }
        }
        prev = sum[i];
    }
    return ans == INT_MAX ? 0 : ans;
}

// my attempt at the 2-ptr where we go backwards
int minSubArr2ptr(vector<int>& nums, int s) {
    return 0;
}

int main() {
    vector<int> v1 = {1,2,3,4,8};
    cout << minSubArr(v1, 8) << endl;
    vector<int> v2 = {2,3,1,2,4,3};
    cout << minSubArr(v2, 7) << endl;
}


