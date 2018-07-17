// quick sieve of eratosthenes

#include <iostream>
#include <vector>
#include <math.h> // only for floor and sqrt root

using namespace std; 

// find all primes under n
vector<int> seive(int n) {
    int* arr = new int[n + 1];  
    vector<int> res;
    for(int i = 2; i < floor(sqrt(n)); ++i) {
        if(arr[i] == 0) {
            for(int j = i * i; j < n; j += i) {
                arr[j] = 1;
            }
        }    
    }    
    for(int i = 1; i < n; ++i) {
        if(arr[i] == 0) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    vector<int> res = seive(100);
    for(int i : res) { cout << i << " "; }
    cout << endl;
}
