#include <iostream>
#include <vector>

using namespace std;

// find cycle.
// 0 = idk
// 1 = cycle node
// 2 = terminal node
bool dfs(vector<vector<int>>& nodes, vector<int>& visited,int n) {
    if(visited[n] > 0) return visited[n] == 2;
    vector<int> edges = nodes[n];
    visited[n] = 1;
    for(int e: edges) {
        if(dfs(nodes, visited, e) == false) { return false; }
    }
    visited[n] = 2;
    return true;
}

vector<int> safe(vector<vector<int>> nodes) {
    int n = nodes.size();
    vector<int> safenodes;
    vector<int> visited = vector<int>(n, 0);
    for(int i = 0; i < n; ++i) {
        if(visited[i] == 2) { safenodes.push_back(i); }
        if(visited[i] == 0 && dfs(nodes,visited,i)) { safenodes.push_back(i); }
    }
    for(int v : safenodes) {
        cout << v << " ";
    }
    cout << endl;
    return safenodes;
}

int main() {
    vector<int> e1 = {1,2};
    vector<int> e2 = {2,3};
    vector<int> e3 = {5};
    vector<int> e4 = {0};
    vector<int> e5 = {5};
    vector<int> e6 = {};
    vector<int> e7 = {};
    vector<vector<int>> nodes;
    nodes.push_back(e1);
    nodes.push_back(e2);
    nodes.push_back(e3);
    nodes.push_back(e4);
    nodes.push_back(e5);
    nodes.push_back(e6);
    nodes.push_back(e7);

    safe(nodes);
    cout << "Should be something 2 4 5 6" << endl;
}
