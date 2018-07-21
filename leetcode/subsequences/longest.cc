// 673 Leetcode

// naive brute force first

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>>& subs, unordered_set<int>& indices, 
        vector<int>& ref, vector<int>& cur, int index) 
{
    if(cur.size() > 1 && index == ref.size()) { subs.push_back(cur); }
    
    unordered_set<char> dups;
    for(int i = index; i < ref.size(); ++i) {
        if((cur.size() == 0 || ref[i] > cur.back()) 
                && dups.find(ref[i]) == dups.end()
                && indices.find(i) == indices.end())  
        {
            cur.push_back(ref[i]);
            dups.insert(ref[i]);
            indices.insert(i);
            dfs(subs, indices, ref, cur, i+1);
            cur.pop_back();
        }
    }    
}

int num_longest(vector<int>& arr) {
    vector<vector<int>> res;
    vector<int> cur;
    unordered_set<int> indices;
    dfs(res, indices, arr, cur, 0);

    for(vector<int> v : res) {
        cout << "[";
        for(int i : v) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}


int main() {
    vector<int> v1 = {1,3,5,4,7};
    cout << num_longest(v1) << endl;
}
