#include <algorithm>
// 
// root + (root.left.left) + root.left.right + root.right.right + ...
// root.left + root.right
class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

int rob(TreeNode* root) {
    if(!root) {
        return 0;
    } 
    int val = 0;
    if(root->left) {
        val += rob(root->left->left) + rob(root->left->right);
    }
    if(root->right) {
        val += rob(root->right->left) + rob(root->right->right);
    }
    return std::max(val + root->data, rob(root->left) + rob(root->right));
}
