#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>&);
int maxProductDP(vector<int>&);

// maximum product array
int main() {
    vector<int> t1 = {3,-1,4,2};
    vector<int> t2 = {0,2};
    cout << maxProduct(t1) << " " << endl;
    cout << maxProductDP(t2) << " " << endl;
    return 0;
}

// no DP starting from both sides
int maxProduct(vector<int>& A) {
    int n = A.size();
    int global = 1;
    int front = 1;
    int back = 1;
    for(int i = 0; i < n; i++) {
       front *= A[i];
       back *= A[n - i - 1];
       global = max(global, max(front,back));
       front = front == 0 ? 1 : front;
       back = back == 0 ? 1 : back;
    }
    return global;
}

// DP version, one iterations
int maxProductDP(vector<int>& A) {
    int n = A.size();
    int* minlist = new int[n];
    int* maxlist = new int[n];
    minlist[0] = A[0];
    maxlist[0] = A[0];
    int global = A[0];
    for(int i = 1; i < n; i++) {
        if(A[i] != 0) {
            minlist[i] = min(global, min(minlist[i-1] * A[i], maxlist[i - 1] * A[i]));
            maxlist[i] = max(global, max(minlist[i-1] * A[i], maxlist[i - 1] * A[i]));
            global = global == 0 ? 1 : max(maxlist[i], global);
        }
    }
    return global;
}


