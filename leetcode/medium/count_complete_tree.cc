#include <iostream>
#include <stack>


using namespace std;

struct TreeNode*
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : data(v), left(nullptr), right(nullptr) {}
};

int count_complete_btree(Treenode* root)
{
    if(!root) return 0;
    int total = 0;
    stack<TreeNode*> nodes;
    nodes.push(root);


    while(!nodes.empty())
    {
        TreeNode* cur = nodes.top();
        total++;
        nodes.pop();
        if (cur->left)
        {
            nodes.push(cur->left);
        }
        if (cur->right)
        {
            nodes.push(cur->right);
        }
    }

    return total;
}

int count_complete_btree2(Treenode* root)
{
    if(!root) return 0;
    int total = 0;
    stack<TreeNode*> nodes;
    TreeNode* cur = root;


    while(cur || !nodes.empty())
    {
        if (cur)
        {
            nodes.push(cur);
            cur = cur->left;
            total++;
        }
        else
        {
            cur = nodes.top()->right;
            nodes.pop();
        }
    }

    return total;
}
