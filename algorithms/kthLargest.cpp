// Kth Largest element implementation, find the kth largest element in a given vector of ints
// 1. Regular Sort
// 2. Max/Min Heap Implementation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sortingKth(vector<int>&, int);
int heapKth(vector<int>&, int);

int main() {
    vector<int> a = {1,1,1,1,1,3};

    // Testing
    cout << "Test 1: " << sortingKth(a,1) << endl;
    cout << "Test 2: " << sortingKth(a,3) << endl;
}

// sorting
int sortingKth(vector<int>& a, int k) {
    sort(a.begin(), a.end());
    return a[a.size() - k + 1];
}

// heap implementation
int heapKth(vector<int>& a, int k) {

}
