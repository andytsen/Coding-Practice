// graph algorithm practice



#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

// a tree is a graph that has these traits: all nodes are connected, and cycle
// returns true if graph is a tree, else false
bool isTree(vector<vector<int>> graph) {
    int n = graph.size();
    
    if(n == 0) return true;
    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int len = q.size();

        for(int l = 0; l < len; ++l) {
            int t = q.front();
            q.pop();
        }
    }

}


// implies that the graph is a tree.

void dfs(vector<vector<int>>& graph) {
    stack<int> stk;
    unordered_set<int> visited;
    int n = graph.size();
    q.push(0);
}

void bfs(vector<vector<int>>& graph) {
    queue<int> q;
    unordered_set<int> visited;
    int n = graph.size();
    q.push(0);

    while(!q.empty()) {
        int len = q.size();
        for(int l = 0; l < len; ++l) {
            int front = q.front();
            q.pop();
            if(visited.find(front) != visited.end()) {
                cout << front << " ";
                visited.insert(front);
                for(int i = 0; i < n; ++i) {
                    if(graph[front][i] == 1 && i != front) {
                        q.push(i);
                    }
                }
            }

        }
    }
}
