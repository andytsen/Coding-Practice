#include <iostream>
#include <vector>

using namespace std;
bool helper(vector<int>& nums, int index) {
    if(index >= nums.size() - 1)
        return true;
    if(nums[index] == 0)
        return false;
    else {
        int len = nums[index];
        bool res = false;
        while(len && index + 1 < nums.size()) {
            index++;
            res = res || helper(nums, index);
            len--;
        }
        return res;
    }
}

bool canJump(vector<int>& a) {
    int i = 0;
    for(int len = 0; i <= len && i < a.size(); i++) {
        len = max(i+a[i], len);
    }
    return i == a.size();
}

int main() {
    vector<int> a = {2,3,1,1,4};
    vector<int> b = {3,2,1,0,4};
    vector<int> c = {2,0};

    cout << helper(a,0) << " ";
    cout << helper(b,0) << " ";
    cout << helper(c,0) << endl;

    cout << canJump(a) << " ";
    cout << canJump(b) << " ";
    cout << canJump(c) << endl;

    return 0;
}


