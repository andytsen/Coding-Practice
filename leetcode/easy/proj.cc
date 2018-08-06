// Leetcode : https://leetcode.com/problems/projection-area-of-3d-shapes/description/

// Andy Tseng

#include <vector>
#include <iostream>

using namespace std;

int proj(vector<vector<int>>& grid) {
    int top = 0;
    int vmax = grid[0][0];
    int hmax = grid[0][0];
    
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            if(grid[i][j]) 
                top++;
            vmax = max(vmax, grid[i][j]);
        }
        cout << vmax << " ";
        top += vmax;
    }

    for(int i = 0; i < grid[0].size(); ++i) {
        for(int j = 0; j < grid.size(); ++j) {
            hmax = max(hmax, grid[i][j]);
        }
        cout << hmax << " ";
        top += hmax;
    }
    return top;
}

int main() {

}
