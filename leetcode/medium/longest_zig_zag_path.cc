#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int res = 0;

void dfs(TreeNode* root, int& left, int& right)
{
    if(!root) 
    {
        right--;
        left--;
        return;    
    }
    
    left++;
    right++;
    dfs(root->left, left, right);    
    dfs(root->right, left, right);    
    res = max({ res, left, right });
}

int longest_zig_zag()
{
    int left,right = 0;
    dfs(root, left, right);
    return res;
}
