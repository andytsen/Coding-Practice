#include <vector>
#include <iostream>

using namespace std;
// goal:
// O(m+n)
// O(1)
// vectors always are positive nums, if -1 then v1 is the open memory slot
vector<int> merge_arr(vector<int> v1, vector<int> v2) {
    int free_ind = 0;
    for(int i  = 0; i < v1.size(); ++i) {
        if(v1[i] == -1) free_ind = i;
    } 

    int total = free_ind + v2.size();
    int n = v2.size();
    int m = free_ind - 1;
    while(m > 0 && n > 0) {
        if(v1[m - 1] > v2[n - 1]) {
            v1[total-1] = v1[m-1];
            m--;
        } else {
            v1[total-1] = v2[n-1];
            n--;
        }   
    }
    while(n--) {
        v1[n-1] = v2[n-1];
    }
    return v1;
}

int main() {
    vector<int> v1 = {1,2,3,-1,-1,-1}; 
    vector<int> v2 = {1,2,2};
    merge_arr(v1,v2);
    return 0;
}
