#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2);
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2);

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    // Test 1
    vector<int> ans = intersection1(nums1, nums2);
    for(auto a : ans) {
        cout << a << " ";
    }
    cout << endl;

    // Test 2


    return 0;
}

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> refer(nums1.begin(), nums1.end());
    vector<int> ans;
    for(int a : nums2) {
       if(refer.count(a)) {
          ans.push_back(a);
          refer.erase(a);
       }
    }
    return ans;
}
