// ------------------
// Mergesort algorithm for all vectors
// by Andy Tseng
//
// ------------------

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void merge(vector<T>& a, int low, int mid, int high) {
    if(low == high) return;
    int i = low;
    int j = mid;
    vector<T> ss;
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

template<typename T>
void merge_sort(vector<T>& a, int low, int high) {
    if(high - low == 1) {
        if(a[low] > a[high]) {
            T tmp = a[low];
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

template<typename T>
void merge_sort(vector<T>& a) {
    merge_sort(a, 0, a.size() - 1);
}

int main() {
    cout << "--- TEST 1 ---" << endl;
    vector<int> t1 = {1, 5, 3, 9, 2, -1};
    merge_sort(t1, 0, t1.size() - 1);
    for(int i : t1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> t2 = {9, 4, -1};
    merge_sort(t2, 0, t2.size() - 1);
    cout << "--- TEST 2 ---" << endl;
    for(int i : t2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "--- TEST 3 ---" << endl;
    vector<double> t3 = {4.1, 9.0001, 5.000023, 3.14159, 1.09, 0.993};
    merge_sort(t3);
    for(double db : t3) {
        cout << db << " ";
    }
    cout << endl;

    return 0;
}
