// Sliding Windows
// use k-sized tree to store the window.

#include <iostream> // debug
#include <vector>
#include <deque>

using namespace std; 
vector<int> kwindow(vector<int>& nums, int k) {
    deque<int> dq(k);
    vector<int> res;
    for(int i = 0; i < k; ++i) {
        // check make sure to find the largest.
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]); 

    for(int i = k; i < nums.size(); ++i) {

        while(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        res.push_back(nums[dq.front()]); 
    }
    return res;
}

int main() {
   vector<int> t1 = {1, 3, -1, -3, 5, 3, 6, 10}; 
   vector<int> r = kwindow(t1,3);
   for (int i : r) { cout << i << " "; }
   cout << endl;
   return 0;
}


