#include <iostream> // for debugging
#include <vector>

using namespace std;

int bsearch(vector<int>& arr, int element) {
    int low = 0;
    int high = arr.size() - 1;
    
    while(low <= high) {
        int mid = low + ((high - low) >> 1);
        if(arr[mid] > element) { high = mid - 1; }
        else if(arr[mid] < element) { low = mid + 1; }
        else { return mid; }
    }
    return -1;
}

int main() {
    vector<int> v1 = {7, 18, 21, 30, 55, 60, 75}; 
    cout << bsearch(v1, 21) << endl;
}
