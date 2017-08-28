#include <iostream>
#include <vector>

using namespace std;
int singleNonDuplicate(vector<int>& a) {
    int left = 0;
    int right = a.size() - 1;
    while(left <= right) {
        int mid = left + (right - left)/2;
        if(mid % 2 == 0) {
            if(a[mid] == a[mid-1]) {
                right -= 2;
            }
            else if(a[mid] == a[mid+1]) {
                left += 2;
            }
            else {
               return a[mid];
            }
        } else {
            if(a[mid] == a[mid-1]) {
                left += 2;
            }
            else if(a[mid] == a[mid+1]) {
                right -= 2;
            }
            else { return a[mid]; }
        }
        if(left > a.size() || right < 0) return a[mid];
    }
    return -1;
}

int main() {
    vector<int> v1 = {1,1,2,3,3,4,4};
    cout << singleNonDuplicate(v1) << endl;
    vector<int> v2 = {3,3,7,7,10,11,11};
    cout << singleNonDuplicate(v2) << endl;
    vector<int> v3 = {0,1,1};
    cout << singleNonDuplicate(v3) << endl;
    vector<int> v4 = {1,1,2};
    cout << singleNonDuplicate(v4) << endl;
    return 0;
}
