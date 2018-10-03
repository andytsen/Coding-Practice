// some bst stuff

#include <iostream>
#include <stack>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// how about a stack?
int findKthSmallest(node* root, int k) {
    if(k < 1) return -1;
    stack<node*> stk;
    node* cur = root;

    while(!stk.empty() || cur != nullptr) {
        while(cur) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        k--;
        if(k == 0) {
            return cur->data;
        }

        cur = cur->right;
    }
    return -1;
}

void iterative_pre(node* root) {
    if(!root) return;
    node* cur = root;
    stack<node*> stk;
    stk.push(root);

    while(!stk.empty()) {
        cur = stk.top();
        stk.pop();
        cout <<  cur->data << " ";

        if(cur->right) stk.push(cur->right);
        if(cur->left) stk.push(cur->left);
    }
}

int main() {
    node* root = new node(3);
    node* left1 = new node(2);
    root->left = left1;
    root->right = new node(4);
    cout << findKthSmallest(root, 1) << endl;;
    cout << findKthSmallest(root, 2) << endl;;

    iterative_pre(root);
}












