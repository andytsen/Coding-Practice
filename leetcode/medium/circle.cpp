#include <vector>

using namespace std;
void dfs(vector<vector<int>>& r, vector<int>& visited, int i) {
    for(int j = 0; j < visited.size(); ++j) {
        if(j != i && r[i][j] == 1) {
            dfs(r, visited, j);
        }
    }
}
int friend_circle(vector<vector<int>> relationships) {
    vector<bool> visited(0,relationships.size());  
    int count = 0;
    for(int i = 0; i < relationships.size(); ++i) {
        if(visited[i] == 0) {
            dfs(relationships, visited, i);
            count++;
        }
    }
    return count;
}
