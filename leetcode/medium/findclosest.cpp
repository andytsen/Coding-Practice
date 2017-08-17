#include <iostream>
#include <vector>

using namespace std;

vector<int> findClosestElement(vector<int>& nums, int k, int x) {
    vector<int> ans = vector<int>();
    int r = nums.size() - 1;
    int l = 0;
    int closest = 0;
    while(r - l > 1) {
        int diffleft = abs(nums[l] - x);
        int diffright = abs(nums[r] - x);
        int mid = (r - l)/2;
        if(diffright < diffleft) {
            l += mid;
        } else if(diffleft < diffright) {
            r -= mid;
        } else {
            r -= mid;
        }
    }

    while(k > 0) {
        int diffleft = l >= 0 ? abs(nums[l] - x) : INT_MAX;
        int diffright = r < nums.size() ? abs(nums[r] - x) : INT_MAX;
        if(diffleft > diffright) {
            ans.push_back(nums[r]);
            r++;
        } else {
            vector<int>::iterator it = ans.begin();
            ans.insert(it,nums[l]);
            l--;
        }
        k--;
    }

    /* Debug */
    for(int i : ans)
        cout << i << " ";
    cout << endl;
    cout << "x = " << x << endl;

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
