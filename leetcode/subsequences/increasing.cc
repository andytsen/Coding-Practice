// 491 on leetcode
// Andy Tseng


#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void getss(vector<vector<int>>& res, vector<int>& ref, vector<int>& cur, 
        int index) {
    if(cur.size() > 1) {
        res.push_back(cur);
    }
    unordered_map<int,int> dups;
    for(int i = index; i < ref.size(); ++i) {
        if( (cur.size() == 0 || ref[i] >= cur.back()) && 
            dups.find(ref[i]) == dups.end()) 
        {
            cur.push_back(ref[i]);
            dups[ref[i]] = 1;
            getss(res, ref, cur, i + 1);
            cur.pop_back();
        }
        
    }
}

vector<vector<int>> increasing(vector<int>& ref) {
    vector<vector<int>> res;
    vector<int> cur;
    getss(res, ref, cur, 0);
    return res;
}

vector<vector<int>> iterative_increasing(vector<int>& ref) {
    vector<vector<int>> res;
    const int n = ref.size();
    if(n < 2) return res;

    for(auto i = n - 2; i >= 0; --i) {
        int x = ref[i];
        int len = res.size();
        
        for(int j = 0; j < len; ++j) {
            if(x < res[j][0]) {
                vector<int> cur = res[j];
                cur.insert(cur.begin(), x);
                res.push_back(cur);
            } else if(x == res[j][0]) {
                res[j].insert(res[j].begin(),x);
            }
        }

        unordered_set<int> dups;
        for(int j = i + 1; j < n; ++j) {
            const int y = ref[j];
            if(x <= y && dups.find(y) == dups.end()) {
                res.push_back(vector<int>{x,y});
                dups.insert(y);
            }            
        }
    }

    return res;
}


int main() {
    vector<int> t1 = {1,2,2,4,8}; 
    vector<vector<int>> res = iterative_increasing(t1);
    
    cout << res.size() << endl;
    // print
    for(vector<int> v : res) {
        cout << "[ ";
        for(int i : v) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
}


