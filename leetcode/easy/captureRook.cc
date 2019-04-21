
#include <vector>

using namespace std;

int numRookCaptures(vector<vector<char>>& board) 
{
    int counts = 0;
    for (int i = 0; i < board.size(); ++i) 
    {
        for (int j = 0; j < board[0].size(); ++j) 
        {
            if (board[i][j] == 'R') 
            {
                for(int curI = i - 1; curI >= 0; curI--) 
                {
                    if (board[curI][j] == 'B') {
                        break;
                    }
                    if (board[curI][j] == 'p') {
                        counts++;
                        break;
                    }
                }
                for(int curI = i + 1; curI < 8; curI++) 
                {
                    if (board[curI][j] == 'B') {
                        break;
                    }
                    if (board[curI][j] == 'p') {
                        counts++;
                        break;
                    }
                }
                for(int curJ = j - 1; curJ >= 0; curJ--) 
                {
                    if (board[curI][j] == 'B') {
                        break;
                    }
                    if (board[curI][j] == 'p') {
                        counts++;
                        break;
                    }
                }
                for(int curJ = j + 1; curJ < 8; curJ++) 
                {
                    if (board[curI][j] == 'B') {
                        break;
                    }
                    if (board[curI][j] == 'p') {
                        counts++;
                        break;
                    }
                }
            } 
        }
    }        

}

int main() 
{

}
