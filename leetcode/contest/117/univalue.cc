// Leetcode 956 

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isUniTree(Node* root) {
    if(!root) return true;
    if (root->left && root->left->data != root->data) return false; 
    if (root->right && root->right->data != root->data) return false; 
    return isUniTree(root->left) && isUniTree(root->right);
}
