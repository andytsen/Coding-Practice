// how to get the max sum of an array after k negations.





//  what kind of data structure is storing these numbers?
//  = vector (array)
//  do you have to do exactly K negates?
//  = yes
//  is the length of the array >= k?
//  = No
//
//
//  [ -4 -3 0 1 ] k = 5
//  [4 3 0 1]
//
//  [-5 -2 1 10] k = 5
//  [5 2 -1 10] 3
//  [5 -2 -1 10] 2
//  [5 2 1 10] 0
//
//  O(nlogn) sol

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int maxSumAfterKNegates(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());

    for(int i = 0; k > 0 && i < arr.size(); ++i, k--) {
        arr[i] *= -1;
    }

    int min_elem = INT_MAX;
    for(int i = 0; i < arr.size(); ++i) {
        min_elem = min(arr[i], min_elem);
    }

    return accumulate(arr.begin(), arr.end(), 0) - ((k % 2) * min_elem * 2);
}

int main() {
    vector<int> v1 = {2,4,3};
    cout << maxSumAfterKNegates(v1, 1) << endl;

    vector<int> v2 = {-5, -2, 1, 10};
    cout << maxSumAfterKNegates(v2, 5) << endl;
}
