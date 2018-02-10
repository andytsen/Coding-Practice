// in c++

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    TreeNode* walk = root;
    TreeNode* parent = root;

    // get to the correct node
    while(walk) {
        if(walk->val == key) {
            break;
        }
        else if(walk->val < key) {
            parent = walk;
            walk = walk->right;
        }
        else {
            parent = walk;
            walk = walk->left;
        }
    }
    if(!walk)
        return nullptr;
}
