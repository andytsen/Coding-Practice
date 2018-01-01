#include <iostream>

using namespace std; 
template<typename T>
class my_shared_ptr {
    T* ptr; 
    int* count;
    public:
        explicit my_shared_ptr(T* p) : ptr(p), count(new int(1)) {}

        my_shared_ptr ( const my_shared_ptr& rhs) : ptr(rhs.ptr) { 
            (*(rhs.count))++;
            this->count = rhs.count;
        }

        my_shared_ptr& operator =(const my_shared_ptr& rhs) {
            int cur = (*(this->count))--;
            if(cur == 0) { delete this->ptr; }
            this->ptr = rhs.ptr;
            this->count = rhs.count;
            (*(rhs.count))++;
            return *this;
        }

        T operator *() {
            return *(this->ptr);
        }

        T* operator ->() {
            return this->ptr;
        }

        ~my_shared_ptr() {
            int cur = (*(this->count))--;
            if(cur == 0) {
                delete this->ptr;
            }
        } 
};

int main() {
    my_shared_ptr<int> ss(new int(3));
    my_shared_ptr<int> st = ss;
    if(*ss == *st) { cout << "--- t1 passed ---" << endl; }
    return 0;
}
