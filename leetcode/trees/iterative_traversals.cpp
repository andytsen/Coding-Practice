#include <iostream>
#include <vector>
#include <stack> // used in iterative storing nodes

using namespace std;

struct TreeNode* {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> pre_order(TreeNode* root) {
    vector<int> vals;
    if(!root) return vals;
    stack<TreeNode*> stk;
    stk.push_back(root);
    while(!stk.empty()) {
        TreeNode* walk = stk.top();
        vals.push_back(walk->val);
        stk.pop();
        if(walk->right) stk.push(walk->right);
        if(walk->left) stk.push(walk->left);
    }
    return vals;
}

vector<int> inorder(TreeNode* root) {
    vector<int> vals;
    if(!root) return vals;
    stack<TreeNode*> stk;
    TreeNode* walk = root;
    while(!stk.empty() || walk) {
        if(walk) {
            stk.push(walk);
            walk = walk->left;
        }
        else {
            walk = stk.top();
            vals.push_back(walk->val);
            stk.pop();
            walk = walk->right;
        }
    }
    return vals;
}

vector<int> post_order(TreeNode* root) {
    vector<int> vals;
    if(!root) return vals;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()) {
        root = stk.top();
        vals.push_back(root->val);
        stk.pop();
        if(root->right) stk.push(root->right);
        if(root->left) stk.push(root->left);
    }
    return vals;
}

// Morris Traversal
vector<int> morris_pre(TreeNode* root) {}

vector<int> morris_in(TreeNode* root) {}

vector<int> morris_post(TreeNode* root) {}

int main() {
    TreeNode* root()
    return 0;
}
