// 334 on Leetcode
// Andy Tseng

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool contains_triplet(vector<int>& nums) {
    int mid = INT_MAX;
    int low = INT_MAX;

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] <= low) {
            low = nums[i];
        }
        else if(nums[i] <= mid) {
            mid = nums[i];
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> test1 = {5,4,3,2,1};
    cout << contains_triplet(test1) << endl;
    vector<int> test2 = {1,2,3,2,1,6,2};
    cout << contains_triplet(test2) << endl;
    vector<int> test3 = {1,0,0,2};
    cout << contains_triplet(test3) << endl;
    return 0;
}
