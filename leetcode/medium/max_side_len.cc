#include <vector>

using namespace std;

int max_side_length(vector<vector<int>>& mat, int threshold)
{
    vector<vector<int>> pc_mat = mat;
    int s = 0;
    for (int i = 0; i < mat.size(); ++i)
    {
        s += mat[i][0];
        pc_mat[i][0] = s; 
    }
    s = 0;
    for (int j = 0; j < mat[0].size(); ++j)
    {
        s += mat[0][j];
        pc_mat[0][j] = s; 
    }
    for (int i = 1; i < mat.size(); ++i)
    {
        for (int j = 1; j < mat[0].size(); ++j)
        {
            pc_mat[i][j] = pc_mat[i - 1][j] + pc_mat[i][j-1] - pc_mat[i-1][j-1] + mat[i][j];
        }
    }
    
     

}

int main()
{

}
