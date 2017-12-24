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
            int tmp = a[low];
            a[low] = a[high];
            a[high] = tmp; 
        }
    }
    else if(high > low) {
        int mid = (high >> 1) + low;
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
    if(low == high) return;
    int i = low;
    int j = mid;
    vector<int> ss;
    while(i < mid || j < high) {
        if(i >= mid) {
            ss.push_back(a[j]);
            ++j;
        }
        else if(j >= high) {
            ss.push_back(a[i]);
            ++i;
        } else if(a[i] < a[j]) {
            ss.push_back(a[i]);
            ++i;
        } else {
            ss.push_back(a[j]);
            ++j;
        }
    }
    for(int k = low; k < high; ++k) {
        a[k] = ss[k - low];
    }
}

int main() {
    cout << "TEST 1: " << endl;
    vector<int> t1 = {1, 5, 3, 9, 2, -1};
    merge_sort(t1, 0, t1.size() - 1);
    for(int i : t1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> t2 = {9, 4, -1};
    merge_sort(t2, 0, t2.size() - 1);
    cout << endl;
    cout << "TEST 2: " << endl;
    for(int i : t2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
