#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node(int v) : data(v), next(nullptr) {}
};

// reverse a linked list
node* reverse(node* head) {
    node* walk = head;
    node* prev = nullptr;
    while(walk) {
        node* next = walk->next;
        walk->next = prev;
        prev = walk;
        walk = next;
    }
    return prev;
}

int main() {
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    node* r = reverse(n1);
    
    node* walk = r;
    while(walk) { 
        cout << walk->data << " "; 
        walk = walk->next;
    }
    cout << endl;
    return 0;
}
