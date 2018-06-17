// 417 on leetcode
// dfs using looking for where it goes 
// using bool reference (c++ thing)

// Andy Tseng

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> ocean(vector<vector<int>>& mat);
void dfs(vector<vector<int>>&,int,int,bool&,bool&);

int main() {
    vector<int> v1 = {1,2,2,3,5};
    vector<int> v2 = {3,2,3,4,4};
    vector<int> v3 = {2,4,5,3,1};
    vector<int> v4 = {6,7,1,4,5};
    vector<int> v5 = {5,1,1,2,4};
    vector<vector<int>> map;
    map.push_back(v1);
    map.push_back(v2);
    map.push_back(v3);
    map.push_back(v4);
    map.push_back(v5);
    vector<pair<int,int>> p = ocean(map);
    
    cout << "Solution: " << endl;
    for(pair<int,int> i : p) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}

vector<pair<int,int>> ocean(vector<vector<int>>& mat) {
    vector<pair<int,int>> points;
    for(int i = 0; i < mat.size(); ++i) {
        for(int j = 0; j < mat[0].size(); ++j) {
            bool reach_pacific = false;;
            bool reach_atlantic = false;
            dfs(mat,i,j,reach_pacific,reach_atlantic);
            if(reach_pacific && reach_atlantic) { points.push_back(pair<int,int>(i,j)); }
        }
    }
    return points;
}

void dfs(vector<vector<int>>& mat, int i, int j, bool& reach_pacific, bool& reach_atlantic) {
    if(mat[i][j] == -1 || (reach_pacific && reach_atlantic)) { return; }
    if(i == 0 || j == 0) {
        reach_pacific = true;
    }
    if(i == mat.size() - 1 || j == mat[0].size() - 1) {
        reach_atlantic = true;
    }

    int old = mat[i][j];
    mat[i][j] = -1; // cant flow in a cycle

    if(i - 1 >= 0 && mat[i-1][j] <= old) {
        dfs(mat,i-1,j,reach_pacific,reach_atlantic);
    }

    if(j - 1 >= 0 && mat[i][j - 1] <= old) {
        dfs(mat,i,j - 1,reach_pacific,reach_atlantic);
    }

    if(i + 1 < mat.size() && mat[i + 1][j] <= old) {
        dfs(mat,i + 1,j,reach_pacific,reach_atlantic);
    }

    if(j + 1 < mat[0].size() && mat[i][j + 1] <= old) {
        dfs(mat,i,j + 1,reach_pacific,reach_atlantic);
    }
    mat[i][j] = old;
}
