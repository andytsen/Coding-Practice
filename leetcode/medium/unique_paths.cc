// Unique Paths 1 and 2
// Andy Tseng 3/13/18

#include <vector>
#include <iostream> //debugging

using namespace std;

// Robot can only move down or right.
int unique_paths(int m, int n) {
    vector<vector<int>> dp = vector<vector<int>>(m,vector<int>(n,0));
    for(int i = 0; i < n; ++i) {
        dp[0][i] = 1;
    }
    for(int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for(int r = 1; r < m; ++r) {
        for(int c = 1; c < n; ++c) {
            dp[r][c] += dp[r-1][c] + dp[r][c-1];
        }
    }
    return dp[m-1][n-1];
}

int unique_paths2(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> dp = vector<vector<int>>(m,vector<int>(n,0));
    for(int i = 0; i < m; ++i) {
        if(board[i][0] == 1) break;
        else dp[i][0] = 1;
    }
    for(int i = 0; i < n; ++i) {
        if(board[0][i] == 1) break;
        else dp[0][i] = 1;
    }
    for(int r = 1; r < m; ++r) {
        for(int c = 1; c < n; ++c) {
            if(board[r][c] == 1) { dp[r][c] = 0; }
            else { dp[r][c] = dp[r-1][c] + dp[r][c-1]; }
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int m,n;
    cin >> m >> n;
    cout << unique_paths(m,n) << endl;  

    vector<vector<int>> board;
    board.push_back(vector<int>{0,0,0});
    board.push_back(vector<int>{0,1,0});
    board.push_back(vector<int>{0,0,0});
    cout << unique_paths2(board) << endl;
    return 0;
}
