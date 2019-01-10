// given a tree, find all the paths that have 3 or more nodes that have consecutive pattern of 1,2,3 ...

#include <vector>
#include <iostream>

using namespace std;


struct node {
    int data;
    node* left;
    node* right;
    node(int v) : data(v), left(nullptr), right(nullptr) {}
};

struct path {
    node* start;
    int len;
    int dir[len];
};

path* findPat(node* root) {

    return nullptr;
}

node* buildTree() {
    node* root = new node(2);
    root->left = new node(4);
    root->right = new node(3);

    node* l2l = root->left;
    l2l->left = new node(6);
    l2l->right = new node(5);
    node* l2r = root->right;
    l2r->right = new node(4);

    node* l3l1 = l2l->right;
    l3l1->left = new node(1);
    l3l1->right = new node(6);
    l4r2 = l3l1->left;
    l4l2->right = new node(2);
    l5m = l4l2->right;
    l5m->left = new node(3);
    l5m->right = new node(5);
    l3l1->right->right = new node(7);
}

int main() {
    node* tree = buildTree();
}
