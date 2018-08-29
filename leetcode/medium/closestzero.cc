// leetcode : https://leetcode.com/problems/01-matrix/description/
// Andy Tseng

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


vector<vector<int>> closest(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>> stk;
    vector<vector<int>> dists = vector<vector<int>>(m, vector<int>(n, INT_MAX));
    for(int i = 0; i < m; ++i) 
        for(int j = 0; j < n; ++j) 
            if(grid[i][j] == 0) {
                dists[i][j] = 0;
                stk.push(pair<int,int>(i,j)); 
            }

    while(!stk.empty()) {
        int r = stk.front().first;
        int c = stk.front().second;
        stk.pop();

        vector<pair<int,int>> neighbors;
        neighbors.push_back(pair<int,int>(r - 1, c)); 
        neighbors.push_back(pair<int,int>(r + 1, c)); 
        neighbors.push_back(pair<int,int>(r, c - 1)); 
        neighbors.push_back(pair<int,int>(r, c + 1)); 

        for(pair<int,int> n : neighbors) {
            if(n.first < grid.size() && n.first >= 0 && n.second < grid[0].size() && 
                    n.second >= 0 && dists[n.first][n.second] > dists[r][c] + 1) 
            {
                dists[n.first][n.second] = dists[r][c] + 1;
                stk.push(n);
            }       
        }
    }
    return dists;
}

int main() {
    cout << "TEST 1 ~~~~~~~ " << endl;
    vector<int> t1r1 = {0, 0, 0};
    vector<int> t1r2 = {0, 1, 0};
    vector<int> t1r3 = {0, 0, 0};

    vector<vector<int>> g1;
    g1.push_back(t1r1);
    g1.push_back(t1r2);
    g1.push_back(t1r3);
    vector<vector<int>> a1 = closest(g1);

    for(int i = 0; i < a1.size(); ++i) {
        for(int j = 0; j < a1[i].size(); ++j) 
            cout << a1[i][j] <<  " ";
        cout << endl;
    }
    cout << endl;

    
    cout << "TEST 2 ~~~~~~~ " << endl;
    vector<int> t2r1 = {0, 0, 0};
    vector<int> t2r2 = {0, 1, 0};
    vector<int> t2r3 = {1, 1, 1};

    vector<vector<int>> g2;
    g2.push_back(t2r1);
    g2.push_back(t2r2);
    g2.push_back(t2r3);
    vector<vector<int>> a2 = closest(g2);

    for(int i = 0; i < a2.size(); ++i) {
        for(int j = 0; j < a2[i].size(); ++j) 
            cout << a2[i][j] <<  " ";
        cout << endl;
    }
    cout << endl;
}
