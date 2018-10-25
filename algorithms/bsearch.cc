// quick binary search
#include <vector>
#include <iostream>

using namespace std;

int bsearch(vector<int>& arr, int e) {
    int low = 0;
    int high = arr.size();

    while(low <= high) {
        int mid = low + ((high - low) >> 1);

        if(arr[mid] == e) {
            return mid;
        } else if(arr[mid] > e) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}


int main() {
    vector<int> v1 = {-8, 1, 2, 3, 8, 9};
    cout << bsearch(v1, 2) << " = 2" << endl;
}
