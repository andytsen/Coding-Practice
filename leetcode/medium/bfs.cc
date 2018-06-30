// quick bfs implementation

#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
};


// I will print it out in level order but it wont be all that great looking.
void bfs(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()) {
        stack<TreeNode*> tmp;
        while(!nodes.empty()) {
            TreeNodes* t = nodes.top();
            cout << t->val << " ";
            if(t->left) tmp.push(t->left);
            if(t->right) tmp.push(t->right); 
            nodes.pop();
        }
        cout << "\n";
        nodes = tmp;
    }
}

int main() {
    TreeNode* r = new TreeNode(1);
    TreeNode* s = r->left = new TreeNode(2);
    TreeNode* t = r->right = new TreeNode(3);
    return 0;
}
