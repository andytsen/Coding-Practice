#include <iostream>
using namespace std;

typedef struct node 
{
    int data;
    node* left;
    node* right;
} node;

void insert(node* root, int value)
{
    node* newNode = new node(); // important to initialize 
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
        root = newNode;    

    else if(root->data > value)
    {
        if(root->right == NULL)
          root->right = newNode;  
        else
        {
            insert(root->right, value);
        }
    }
    else 
    {
        if(root->left == NULL)
            root->left = newNode;  
        else
        {
            insert(root->left, value);
        }
    }
}
int main() {

}
