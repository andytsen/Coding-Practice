#include <iostream>
#include <vector>

#define max(a,b) ((a) > (b)?(a):(b))
#define min(a,b) ((a) < (b)?(a):(b))
#define rep(i,n) for(int i = 0; i < n; ++i)

int main() {

    return 0;
}

// O(n) complexity
// O(1) space
// If we know a strictly increasing sequence can be made by swapping
// only A[i] and B[i] then we can keep track of natural and swap. 

int minswap(vector<int>& a, vector<int>& b) {
    int natural = 0;
    int swap = 1;
    int n = a.size();
    for(int i = 1; i < n; ++i) {
        int swap2 = 100001;
        int nat2 = 100001;
        if(A[i-1] < A[i] && B[i-1] < B[i]) {
            nat2 = min(nat2, swap);
            swap2 = min(swap2, natural + 1);
        }
        if(A[i-1] < B[i] && B[i-1] < A[i]) {
            nat2 = min(nat2, natural);
            swap2 = min(swap2, swap + 1);
        }
        swap = swap2;
        natural = nat2;
    }
    return min(natural,swap);
}
