#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};



TreeNode* removeLeaves(TreeNode* root, int val)
{
    if(!root) return nullptr;
    root->left = removeLeaves(root->left,val);
    root->right = removeLeaves(root->right,val);
    if (!root->left && !root->right && root->val == val)
    {
        return nullptr;
    }
    return root;
}
