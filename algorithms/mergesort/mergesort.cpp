// Used to sort a vector or array
#include <vector>
#include <iostream>

using namespace std;

void merge_sort(vector<int>&, int, int);
void swap(int&, int&);
void merge(vector<int>&, int, int, int);

void merge_sort(vector<int>& a, int low, int high) {
    if(high - low == 1) {
        if(a[low] > a[high]) {
            int temp = a[high];
            a[high] = a[low];
            a[low] = temp;
        }
    }
    else if(high != low) {
        int mid = (low + high) >> 1;
        merge_sort(a, low, mid - 1);
        merge_sort(a, mid, high);
        merge(a, low, mid, high);
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge(vector<int>& a, int low, int mid, int high) {
    int i = low;
    int j = mid;
    vector<int> ss = vector<int>(high - low);
    while(i < mid - 1 || j < high) {
        if(a[i] < a[j]) {
            ss.push_back(a[i]);
            ++i;
        } else {
            ss.push_back(a[j]);
            ++j;
        }
    }
    for(int i = low; i < high; ++i) {
        a[i] = ss[i - low];
    }
}

int main() {
    vector<int> t1 = {1, 5, 3, 9, 2, -1};
    merge(t1, 0, 3, t1.size());

    for(int c : t1) { cout << c << " "; }
    cout << endl;
    return 0;
}
