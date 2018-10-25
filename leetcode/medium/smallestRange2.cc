#include <vector>
#include <iostream>

#define max(a,b) (a > b ? : a : b);
#define min(a,b) (a > b ? : b : a);


using namespace std;

// in order to find the min diff in the max and min of B where B = for all i in A we add or sub K
// Assumptions: A has elements (a.size() > 0)
int smallest(vector<int>& arr, int k) {
    int amin = arr[0] + k;
    int amax = arr[arr.size() - 1] - k;
    int diff = -1;
    for(int i = 1; i < arr.size(); ++i) {
        amax = max(amax, arr[i] + k);
        amin = min(amin, arr[i] - k);
        diff = min(diff, (amax - k) - (amin + k)); 
    }
    return diff;
}

int main() {
    vector<int> v1 = {1,3,6};
    cout << smallest(v1, 3) << endl;
}
