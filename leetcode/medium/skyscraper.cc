// Leetcode : https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/
// Andy Tseng

#include <vector>
#include <iostream>

using namespace std;

// O(n^2) two pass
int max_inc(vector<vector<int>>& skyline) {
    int m = skyline.size();
    int n = skyline[0].size();
    vector<vector<int>> limits;
    
    vector<int> top_down;
    for(int i = 0; i < m; ++i) {
        int cur = -1;
        for(int j = 0; j < n; ++j) {
            cur = max(cur, skyline[i][j]);
        }
        top_down.push_back(cur);
    }
    limits.push_back(top_down);

    vector<int> left_right;
    for(int i = 0; i < n; ++i) {
        int cur = -1;
        for(int j = 0; j < m; ++j) {
            cur = max(cur, skyline[j][i]);
        }
        left_right.push_back(cur);
    }
    limits.push_back(left_right);

    int res = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int l = min(limits[0][i], limits[1][j]);
            res += l - skyline[i][j];
        }
    }
    return res;
}

int main() {
    vector<int> r1 = {3, 0, 8, 4};
    vector<int> r2 = {2, 4, 5, 7};
    vector<int> r3 = {9, 2, 6, 3};
    vector<int> r4 = {0, 3, 1, 0};
    vector<vector<int>> skyline;
    skyline.push_back(r1);
    skyline.push_back(r2);
    skyline.push_back(r3);
    skyline.push_back(r4);
    cout << max_inc(skyline) << endl;
}

