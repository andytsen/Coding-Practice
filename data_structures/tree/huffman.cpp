#include <iostream>
#include <string>
using namespace std;

//Huffman Decoding
void decode_huff(node* root, string s)
{
    node* n = new node();
    n = root;
    int index = 0;
    while(index <= s.length())
    {
        if(n->left == NULL && n->right == NULL)
        {
            cout << n->data;
            n = root;
        }
        else if(s.at(index) == '0')
        {
            n = n->left; 
            index++;
        }
        else
        {
            n = n->right;
            index++;
        }
    }  
}
