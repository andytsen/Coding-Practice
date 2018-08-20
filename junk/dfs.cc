// some floodfill dfs shit

#include <vector>
#include <iostream>
#include <stack>
#define max(a,b) (a > b ? (a) : (b))

using namespace std;

int flood_fill(vector<vector<int>>& grid);

int main() {

    vector<int> row1 = {1, 1, 5};
    vector<int> row2 = {1, 1, 5};
    vector<int> row3 = {4, 2, 8};
    vector<vector<int>> grid;
    grid.push_back(row1);
    grid.push_back(row2);
    grid.push_back(row3);
    cout << flood_fill(grid) << endl;
}

int flood_fill(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    vector<vector<bool>> visited = vector<vector<bool>>(m,vector<bool>(n, false));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            stack<pair<int,int>> p;
            int original_color = grid[i][j];
            int tmp = 0;
            if(visited[i][j] == false)  {
                p.push(pair<int,int>(i,j));
            }
            while(!p.empty()) {
                int x = p.top().first;
                int y = p.top().second;
                visited[x][y] = true;
                tmp++;
                p.pop();
                if(x - 1 >= 0 && grid[x-1][y] == original_color && visited[x-1][y] == false) {
                    visited[x-1][y] = true;
                    p.push(pair<int,int>(x-1, y));
                }
                if(y - 1 >= 0 && grid[x][y - 1] == original_color && visited[x][y - 1] == false) {
                    visited[x][y-1] = true;
                    p.push(pair<int,int>(x, y - 1));
                }
                if(x + 1 < m && grid[x + 1][y] == original_color && visited[x+1][y] == false) {
                    visited[x+1][y] = true;
                    p.push(pair<int,int>(x+1, y));
                }
                if(y + 1 < n && grid[x][y + 1] == original_color && visited[x][y + 1] == false) {
                    visited[x][y+1] = true;
                    p.push(pair<int,int>(x, y + 1));
                }
            }
            res = max(res,tmp);
        }
    }
    return res;
}
