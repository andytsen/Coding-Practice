#include <iostream>
#include <vector>

using namespace std;

// for some reason the code here executes to different constraints on the Leetcode server.
int arrayNesting(vector<int>& nums) {
    int n = nums.size();
    int maxlen = 0;
    vector<bool> dups = vector<bool>(n,false);
    for(int i = 0; i < n; i++) {
        int cur = nums[i];
        int size = 0;
        while(!dups[cur]) {
            dups[cur] = 1;
            cur = nums[cur];
            size++;
        }
        maxlen = max(size,maxlen);
    }
    cout << maxlen << endl;
    return maxlen;
}

int main() {
    vector<int> a = {0,2,1,4,3};
    arrayNesting(a);
    return 0;
}



