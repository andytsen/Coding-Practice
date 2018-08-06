// Leetcode https://leetcode.com/problems/koko-eating-bananas/description/
// Andy Tseng


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i,s,n) for(unsigned int i = s; i < n; ++i)
#define repm(i,s,n) for(unsigned int i = n; i >= s; --i);

using namespace std;

bool valid(vector<int>& piles, int H, int k) {
    for(int p : piles) {
        int num = ((p - 1)/k) + 1;
        H -= num;
    }
    return H < 0 ? false : true;
}

int min_k_eating(vector<int>& piles, int H) {
    int low = 0;
    int high = piles[0];
    for(int p : piles) {
        high = max(p,high);
    }

    while(low < high) {
        int mid = low + (high - low)/2;
        if(!valid(piles, H, mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    vector<int> v1 = {30, 11, 23, 4, 20};
    cout << min_k_eating(v1, 5) << endl;
    cout << min_k_eating(v1, 6) << endl;
    vector<int> v2 = {3,6,7,11};
    cout << min_k_eating(v2, 8) << endl;
    return 0;
}
