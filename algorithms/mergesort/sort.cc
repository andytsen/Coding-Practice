// mergesort practice
//

#include <vector> //input format

#include <algorithm> // debugging sort(...)
#include <iostream> // debugging

using namespace std; 

// funcs
void merge_sort(vector<int>& arr);
void sort_recurse(vector<int>&, int, int);

void merge_sort(vector<int>& arr) {
    sort_recurse(arr, 0, arr.size()); 
}

void sort_recurse(vector<int>& arr, int begin, int end) {
    if(end - begin == 1) {
        return;
    } else if(end - begin == 2) {
        int a = arr[begin];
        int b = arr[end - 1];
        if(a > b) {
            int tmp = arr[begin];
            arr[begin] = arr[end-1];
            arr[end-1] = tmp;
        }
    } else {
        int mid = (end - begin) / 2;
        sort_recurse(arr, begin, mid + 1);
        sort_recurse(arr, mid+1, end);
    }
    

}

int main() {
    return 0;
}
