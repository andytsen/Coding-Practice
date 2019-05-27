// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Andy Tseng


#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : data(v), left(nullptr), right(nullptr) {}
};

int sum_root_to_leaf(TreeNode* root) {
    stack<pair<TreeNode*,int>> stk;
    if (!root) return 0;
    stk.push(pair<TreeNode*,int>(root, root->data));   
    int total = 0;

    while (!stk.empty()) {
        pair<TreeNode*,int> node_info = stk.top();
        stk.pop();
        // check if leaf
        TreeNode* cur = node_info.first;
        if(!cur->left && !cur->right) {
            total += node_info.second; 
        }
        if (cur->right) {
            stk.push(pair<TreeNode*,int>(cur, node_info.second * 2 + cur->right->data);
        }
        if (cur->left) {
            stk.push(pair<TreeNode*,int>(cur, node_info.second * 2 + cur->left->data);
        }
    }
    return total;
}
