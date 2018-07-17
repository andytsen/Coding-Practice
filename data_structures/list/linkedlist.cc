
#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node(int v) : data(v), next(NULL) {}
};

class LinkedList {
    node* head;

    public:
        LinkedList() : head(NULL) {}

        void add(int v) {
            node* newNode = new node(v);
            node* walk = head;
            if(walk) {
                while(walk->next) {
                    walk = walk->next;
                }
                walk->next = newNode;
            } else {
                head = newNode;
            }
        }    

        bool remove(int v) {
            node* walk = head;
            node* prev = NULL;
            while(walk) {
                if(walk->data == v) {
                    break;
                }
                prev = walk;
                walk = walk->next;
            }    

            if(!walk) { return false; }

            if(prev) {
                prev->next = walk->next;
            } else {
                head = walk->next;
            }

            delete walk;
            return true;
        }

        void print() {
            node* walk = head;
            cout << "[ ";
            while(walk) {
                cout << walk->data << " ";
                walk = walk->next;
            }
            cout << "]" << endl;
        }
};


int main() {
    LinkedList* l1 = new LinkedList(); 
    l1->add(1);
    l1->add(2);
    l1->add(3);
    l1->add(4);
    l1->add(6);
    l1->print();

    l1->remove(3);
    l1->print();

    l1->remove(2);
    l1->print();
}
