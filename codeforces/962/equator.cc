#include <iostream>
#define repn(i,s,n) for(int i = s; i < n; ++i)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    int total = 0;
    repn(i,0,n) {
        int e;
        cin >> e;
        arr.push_back(e);
        total += e;
    } 
    int cur = 0;
    for(int i = 0; i < arr.size(); ++i) {
        cur += arr[i];
        if(cur > total/2) {
            return i;
        }
    }
    return -1;
}
