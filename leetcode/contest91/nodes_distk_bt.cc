#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// using dfs into bfs , creating a graph 

void make_graph(vector<vector<int>>& graph, TreeNode* cur) {
    if(root->left) {
        graph[cur->left->val][cur->val] = 1;
        graph[cur->val][cur->left->val] = 1;
        make_graph(graph, cur->left);
    }
    if(root->right) {
        graph[cur->right->val][cur->val] = 1;
        graph[cur->val][cur->right->val] = 1;
        make_graph(graph, cur->right);
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* tgt, int K) {
    vector<vector<int>> graph = vector<vector<int>>(501, vector<int>(501,0)); 
    make_graph(graph,root);
    
    stack<int> nodes;
    nodes.push(tgt->val);
    for(int i = 0; i < K; ++i) {
        stack<int> tmp;
        while(!nodes.empty()) {
            int t = nodes.top();
            for(int j = 0; j < graph[t].size(); ++j) {
                if(graph[t][j] == 1) {
                    graph[j][t] = 0;
                    tmp.push(j);
                }
            }
            nodes.pop();
        }
        nodes = tmp;
    }

    vector<int> res;
    while(!nodes.empty()) {
        int t = nodes.top();
        res.push_back(t);
        nodes.pop();
    }
    return res;
}
