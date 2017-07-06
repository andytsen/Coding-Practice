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
    else {
        int mid = (low + high) >> 1;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
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
    int j = mid + 1;
    int n = (mid - low + 1) + (high - mid + 2);
    for(int i = 0; i < n; i++) {
        if(a[i] > a[j]) {
            swap(a[i], a[j]);
            i++;
        }
        else { j++; }
    }
}

int main() {
    int a = 5;
    int b = 10;
    swap(a,b);
    cout << a << " " << b << endl;
    return 0;
}
