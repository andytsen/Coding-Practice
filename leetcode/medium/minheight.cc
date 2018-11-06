// leetcode https://leetcode.com/problems/minimum-height-trees
// Andy Tseng


#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;


vector<int> minHeight(int n, vector<pair<int,int>>& edges) {
    vector<vector<bool>> tree = vector<vector<bool>>(n, vector<bool>(n, 0)); 
    vector<int> degrees = vector<int>(n, 0);

    for(pair<int,int> e : edges) {
        tree[e.first][e.second] = true; 
        tree[e.second][e.first] = true; 
        degrees[e.first]++;
        degrees[e.second]++;
    }

    queue<int> q;
    unordered_set<int> visited;
    for(int i = 0; i < n; ++i) {
        if(degrees[i] == 1) {
            q.push(i);
        }
    } 

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        if(visited.find(front) != visited.end() && degree[front] > 1) {
            q.push(front);
        }
    }
}
