#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};


bool is_complete_tree(TreeNode* root)
{
    std::queue<TreeNode*> q;
    if(root)
    {
        q.push(root);
    }
    bool null_found = false;
    while(!q.empty())
    {
        TreeNode* cur = q.front();
        q.pop();
        if (cur->left)
        {
            q.push(cur->left);
        }
        else
        {
            null_found = true;
        }

        if (cur->right)
        {
            q.push(cur->right);
        }
        else
        {
            null_found = true;
        }
    }
    
    return true;
}

int main()
{
    return 0;
}
