#include <cstdio>

typedef struct node node;
struct node {
    uint32_t addr;
    uint32_t next;
    node() : addr(0), next(0) {}
    int get_data() {
        int* s = (int*)(this->addr);
        return *s;
    }
    void set_data(int v) {
        int* s = (int*)(this->addr);
        *s = v;
    }
    node* get_next() {
        return (node*)(this->next);
    }
    node* set_next(node* n) {
        next = (uint32_t)(n);
    }
};

node* head = nullptr;

void insert(node* h, int v) {
    node* newNode = new node();
    newNode->set_data(v);
    node* h = head;
    while(h->get_next() != 0) {
        h = h->get_next();
    }
    h->set_next(newNode);
}

    
int main() {
    insert(head, 10); 
    insert(head, 11);
    insert(head, 15);
    insert(head, 16);
}
