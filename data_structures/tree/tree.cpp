// hackerrank excercise for tree functions
#include <iostream>
using namespace std;
/*
struct node
{
    int data;
    node* left;
    node* right;
};
*/

void preOrder(node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }    
}

void postOrder(node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }    
}

void inOrder(node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }    
}

node *insert(node* root, int value)
{
    node* newNode;
    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;

    if(value > root->data)
    {
        if(root->right != NULL)
            insert(root->right, value);
        else
            root->right = newNode;
    } 
    else 
    {
        if(root->left != NULL)
            insert(root->left, value);
        else
            root->left = newNode;
    }
    return root;
}
/*
int main()
{
    return 0;
}
*/

