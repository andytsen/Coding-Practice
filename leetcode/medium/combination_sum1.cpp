#include <iostream>
#include <vector>

using namespace std;

void recur_combination(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int tgt, int start);
vector<vector<int>> combination(vector<int>& nums, int tgt);

int main() {
    vector<int> a = {2, 3, 6, 7};
    sort(a.begin(), a.end());
    vector<vector<int>> res = combination(a, 7);
    cout << endl;
    for(vector<int> v : res) {
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

vector<vector<int>> combination(vector<int>& nums, int tgt) {
    vector<vector<int>> res; 
    vector<int> cur;
    recur_combination(res, cur, nums, tgt, 0);
    return res;
}

void recur_combination(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int tgt, int start) {
    if(tgt < 0) {
        return;
    }
    else if(tgt == 0) {
        res.push_back(cur);
    } else {
        for(int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            recur_combination(res, cur, nums, tgt - nums[i], i);
            cur.erase(cur.end() - 1);
        }
    }
}
