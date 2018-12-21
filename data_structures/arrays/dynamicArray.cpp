#include <iostream>

using namespace std;


class dynArray {
    int* data;
    unsigned int current_size; // current size where the largest element
    unsigned int actual_size = 1000; // actual size of the internal array

    void resize(unsigned int new_size) {
        
    }

public:
    
    dynArray() : current_size(0) {
        data = new int[actual_size];
    }
      
    ~dynArray() {
        delete data;
    }

    int& operator[] (int index) {
        if(index > current_size) current_size = index;
        if(index > actual_size) {
            int new_size = actual_size + index;
            resize(new_size);
        }
        return data[index];
    }




};
