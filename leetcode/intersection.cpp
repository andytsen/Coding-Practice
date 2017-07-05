#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int sub1 = 0;
    int sub2 = 0;
    while(sub1 < nums1.size() && sub2 < nums2.size()) {
        if(nums1[sub1] == nums2[sub2]) {
            ans.push_back(nums1[sub1]);
            while(sub1+1 < nums1.size() && nums1[sub1] == nums1[sub1+1]) {
                sub1++;
            }
            while(sub2 < nums2.size() && nums2[sub2] == nums2[sub2+1]) {
                sub2++;
            }
        }
        else if(nums1[sub1] < nums2[sub2]) {
            sub1++;
        }
        else {
            sub2++;
        }
    }
    return ans;
}

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = intersection(nums1, nums2);
    return 0;
}
