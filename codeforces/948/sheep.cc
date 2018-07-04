#include <vector>
#include <iostream>

using namespace std;
using VI = vector<int>;

int main() {
    int n,m;
    cin >> m >> n;
    vector<vector<char>> board = vector<vector<char>>(m, vector<char>(n,'.'));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
           cin >> board[i][j];  
        }
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(board[i][j] == 'W') {
                // check if you see 'S' around you
            }
        }
    }
    return 0;
}
