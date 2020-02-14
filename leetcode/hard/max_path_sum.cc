// Leetcode: https://leetcode.com/problems/binary-tree-maximum-path-sum/
#include <iostream>

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int ans = INT_MIN;


int max(int a, int b)
{
    return (a < b) ? b : a;
}

int dfs(TreeNode* root) 
{
    if(!root)
        return 0;
    int left =  dfs(root->left);
    int right = dfs(root->right);
    if (left < 0)  left = 0;
    if (right < 0) right = 0;
    int path_with_root = left + right + root->val;
    int path_no_root = max(left,right) + root->val;
    ans = max(path_with_root, ans);
    return path_no_root;
}

int max_path_sum(TreeNode* root)
{
    return dfs(root);
}

int main()
{
    TreeNode* root = new TreeNode(-10);
    TreeNode* left_lvl_1 = new TreeNode(9);
    TreeNode* right_lvl_1 = new TreeNode(20);
    TreeNode* right_lvl_1_left_lvl_2 = new TreeNode(15);
    TreeNode* right_lvl_1_right_lvl_2 = new TreeNode(7);

    root->left = left_lvl_1;
    root->right = right_lvl_1;
    right_lvl_1->left = right_lvl_1_left_lvl_2;
    right_lvl_1->right = right_lvl_1_right_lvl_2;

    std::cout << max_path_sum(root) << std::endl;
}



