#include <iostream>
#include <vector>

using namespace std;

bool is_monotonic(vector<int>& arr) {
    if(arr.size() <= 1) return true;
    bool is_greater = arr[0] >= arr[1];  
    for(int i = 1; i < arr.size(); ++i) {
        if(is_greater) {
            if(arr[i-1] < arr[i]) return false; 
        } else {
            if(arr[i-1] > arr[i]) return false;
        }
    }
    return true;
}

int main() {
    return 0;
}
