#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int check_bounds(int,int,int);

/*
int recurs(vector<vector<char> >& board, int steps, int x, int y, int N) {
    if(check_bounds(x,y,N)) {
        if(board[x][y] == 'T') {
            return steps;
        }
        if(board[x][y] == '0') {
            int r1 = recurs(board, steps+1, x - 1, y, N);
            int r2 = recurs(board, steps+1, x + 1, y, N);
            int r3 = recurs(board, steps+1, x, y + 1, N);
            int r4 = recurs(board, steps+1, x, y - 1, N);
            return min(min(min(r3,r4),r2),r1);
        }
        return INT_MAX; 
    } else {
        return INT_MAX;
    }
}
*/

int check_bounds(int k, int l, int N) {
    return (k >= 0 && k < N && l >= 0 && l < N);
}

int main() {
    int N;
    int Mx,My;
    int Tx,Ty;
    cin >> N;
    vector< vector<char> > board(N, vector<char>(N, ' '));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 'M') {
                Mx = i;
                My = j;
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(board[i][j] >= '1' && board[i][j] <= '9') {
                int range = board[i][j] - '0';
                for(int k = i - range; k <= i + range; ++k) {
                    for(int l = j - range; l <= j + range; ++l) {
                        double d = sqrt(pow((k-i),2) + pow((l - j),2)); 
                        if(d < (double)(range) && 
                            check_bounds(k,l,N))
                        {
                            board[k][l] = 'X'; 
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }

    //int res = recurs(board, 0, Mx, My, N);
    //cout << res << endl;    
}
