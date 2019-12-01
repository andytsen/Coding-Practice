#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class SafeBinaryTree
{

public:
    SafeBinaryTree(TreeNode* root)
    {
        data = root; 
    }
    
    bool find(int target)
    {
        if(!data) 
        {
            return;
        }

        data->val = 0;
        stack<TreeNode*> stk;
        stk.push(data);
        while(!stk.empty())
        {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur->left)
            {
                cur->left->val = cur->val * 2 + 1;
                stk.push(cur->left);
            }
            
            if (cur->right)
            {
                cur->right->val = cur->val * 2 + 2;
                stk.push(cur->right);
            }
        }
    }

private:
    TreeNode* data;
};



class SafeBinaryTree2
{

public:
    SafeBinaryTree2(TreeNode* root)
    {
        if(!root) 
        {
            return;
        }

        root->val = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur->left)
            {
                cur->left->val = cur->val * 2 + 1;
                stk.push(cur->left);
            }
            
            if (cur->right)
            {
                cur->right->val = cur->val * 2 + 2;
                stk.push(cur->right);
            }
        }
        data = root;
    }
    
    bool find(int target)
    {
        if(!data) 
        {
            return false;
        }

        data->val = 0;
        int v = data->val;
        int tmp = target;
        while (tmp > v * 2 + 2)
        {
            if (tmp % 2)
            {
                tmp = (tmp - 1) >> 1;
            }
            else 
            {
                tmp = (tmp - 2) >> 1;
            }
        }

        stack<TreeNode*> stk;
        stk.push(data);
        while(!stk.empty())
        {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur->val == target)
            {
                return true;
            }
            if(tmp = cur->val * 2 + 1)
            {
                if (cur->left)
                {
                    stk.push(cur->left); 
                } 
                else
                {
                    return false;
                }
            }
            if(tmp = cur->val * 2 + 2)
            {
                if (cur->right)
                {
                    stk.push(cur->right); 
                } 
                else
                {
                    return false;
                }
            }
        }
        return false;
    }

private:
    TreeNode* data;
};

int main()
{
    TreeNode* n = new TreeNode(1);
}



