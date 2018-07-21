// 456 on leetcode, 132 matching
// find a arr[i], arr[j], arr[k] such that arr[j] > arr[k] > arr[i] such that i < j < k

#include <iostream>
#include <vector>
#include <climits> // INT_MAX and INT_MIN
#include <stack>

#define min(a,b) ( a < b ? (a) : (b) )

using namespace std;

// O(n^2) with others.
bool find_pattern(vector<int>& nums) {
    int low = INT_MAX;

    for(int i = 0; i < nums.size(); ++i) {
        low = min(nums[i], low);
        for(int j = i + 1; j < nums.size(); ++j) {
           if(nums[j] > low && nums[j] < nums[i]) {
               return true;
           }
        }
    }
    return false;

}

bool find_pattern_stack(vector<int>& nums) {
    stack<int> stk;
    vector<int> minarr = vector<int>(nums.size(), INT_MAX);
    minarr[0] = nums[0];

    for(int i = 1; i < nums.size(); ++i) {
        minarr[i] = min(minarr[i-1], nums[i]); 
    }
    for(int j = nums.size() - 1; j >= 0; --j) {
        if(nums[j] > minarr[j]) {
            while(!stk.empty() && stk.top() <= minarr[j]) {
                stk.pop();
            }
            if(!stk.empty() && stk.top() < nums[j]) {
                return true;
            }
            stk.push(nums[j]);
        }
    }
    return false;
}

int main() {
    vector<int> v1 = {1,2,3,4,5};
    cout << find_pattern_stack(v1) << endl;

    vector<int> v2 = {5,4,3,2,1};
    cout << find_pattern_stack(v2) << endl;
    vector<int> v3 = {-1, 10, 5, 8, 7, 6,5,4,3,2,1};
    cout << find_pattern_stack(v3) << endl;

    vector<int> v4 = {5, 10, -1, 3};
    cout << find_pattern_stack(v4) << endl;


    return 0;
}
