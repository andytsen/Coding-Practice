#include <iostream>
using namespace std;

template <typename T>
class vector {
    private:
        T* data; // _a
        int size;
    public:
        vector(int s = 0, const T& v = T()) {
            size = (s == 0) ? 0 : s;
            data = nullptr;
            fill(data, data + size, v);
        }
        ~vector() {
            delete [] data;
            size = 0;
        }
        vector (const vector& rhs) {
            size = rhs.size;
            data = new T[size];
            copy(rhs.data, rhs.data + size, data);
        }
        vector& operator =(const vector& rhs) {
            if(this == rhs) // case where we make x = x
                return *this;
            delete [] data;
            size = rhs.size;
            data = new T[size];
            copy(rhs.data, rhs.data + size, data);
            return *this;
        }
};

int main() {

}
