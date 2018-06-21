// lru cache

#include <unordered_map>

using namespace std;

typedef struct Node node;

struct Node {
    int value;
    int key;
    node* pre;
    node* next;
};

class LRUCache {
    private:
        int size;
        int cap;
        node* head;
        node* tail;
        unordered_map<int,node*> hash;

        void move_to_head(int key) {

        }

    public:
        LRUCache(int capacity) : cap(capacity), size(0), head(nullptr), tail(nullptr) {}

        int get(int key) {
            if(hash.find(key) != hash.end()) {
                return -1; 
            } else {
                move_to_head(key);
                return hash[key]->value;
            }
        }

        void put(int key, int value) {
           if(size < cap) {
                node* n = new node(); 
                n->value = value;
                n->next = nullptr;
                size++;
                if(!tail) {

                }

                head = n;
                hash[key] = n;
           } else {
                // evict someone (the head)
                node* node_to_evict = this->tail;
                hash.erase(node_to_evict->key);               
           }
        }
};
