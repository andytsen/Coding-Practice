#include <iostream>
using namespace std;


struct TreeNode {
    int indx;
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
};

bool insertTreeNode(struct TreeNode* root, struct TreeNode* insertNode)
{
     
    return false;
}

int main() {
    int n;
    cin >> n;
    struct TreeNode* root = NULL;
    for(int i = 1; i <= n; i++)
    {
        struct TreeNode* ins;
        ins->indx = i;
        cin >> ins->val;
        insertTreeNode(root, ins); 
    }


    return 0;
}
