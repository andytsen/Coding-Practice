#include <iostream>
#include <vector>

using namespace std;

// O(n)
vector<int> findClosestElement(vector<int>& nums, int k, int x) {
    vector<int> ans = vector<int>();  
    int i;
    for(i = 0; i + 1 < nums.size(); i++) {
        if(nums[i] < x && nums[i+1] > x) {
            break;
        }
        if(nums[i] == x)
            break;
    }
    if(i == nums.size() - 1)
        i = x < nums[0] ? 0 : nums.size() - 1;
    int l = i;
    int r = i+1;
    while(k > 0) {
        k--;
        int diffleft = l >= 0 ? abs(nums[l] - x) : INT_MAX;
        int diffright = r < nums.size() ? abs(nums[r] - x) : INT_MAX;
        if(diffleft < diffright) {
            vector<int> :: iterator it = ans.begin();
            ans.insert(it,nums[l]);
            l--;
        } else if(diffright < diffleft) {
            ans.push_back(nums[r]);
            r++;
        } else {
            vector<int> :: iterator it = ans.begin();
            ans.insert(it,nums[l]);
            l--;
        }
    }
    return ans;
}

int main() {
    vector<int> test1 = {1,2,6,7,8};
    vector<int> res1 = findClosestElement(test1,2,5);
    vector<int> test2 = {1,2,3,4,5};
    vector<int> res2 = findClosestElement(test2,4,3);
    vector<int> test3 = {1,2,3,4,5};
    vector<int> res3 = findClosestElement(test3,4,2);
    return 0;
}
