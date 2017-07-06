#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool recFindPattern(vector<int>& nums, vector<int>& cur, int index);
bool findPattern(vector<int>& nums);

int main() {
    vector<int> test1 = {3,1,4,2,1};
    cout << findPattern(test1);
    vector<int> test2 = {-1, 3,2,0};
    cout << findPattern(test2);
    return 0;
}

// recursive solution
bool recFindPattern(vector<int>& nums, vector<int>& cur, int index) {
    if(cur.size() == 3) {
        return cur[0] < cur[2] && cur[2] < cur[1] && cur[0] < cur[2];
    } else {
        for(int i = index + 1; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            if(recFindPattern(nums,cur,i))
                return true;
            cur.pop_back();
        }
    }
    return false;
}

bool findPattern(vector<int>& nums) {
    vector<int> cur;
    for(int i = 0; i < nums.size(); i++) {
        cur.push_back(nums[i]);
        if(recFindPattern(nums,cur,i))
            return true;
        cur.pop_back();
    }
    return false;
}

// stack solution ---
bool findPatternWithStack(vector<int>& nums) {
    stack<int> s1;
    stack<int> s2;
    for(int i : nums) {
        if(s1.empty()) {
            s1.push(i);
        }
        if(!s2.empty() && i < s2.top()) {
            // check s1 for more
            
        }
    }
}


