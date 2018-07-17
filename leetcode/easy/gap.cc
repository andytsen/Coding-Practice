// 868 on leetcode

#include <iostream>
#include <bitset>
#define max(a,b) ((a > b) ? (a) : (b))

using namespace std;

int binary_gap(int n) {
    int pre = -1;
    int cur = 0;
    int max_len = 0;
    while(n) {
        int d = n % 2;
        if(d == 1) {
            int len = pre == -1 ? 0 : cur - pre;
            max_len = max(len, max_len);
            pre = cur;
        }
        n = n >> 1;
        cur++;
    }
    return max_len;
}

int main() {
    std::bitset<8> x(9);
    cout << x << endl;
    cout << binary_gap(9) << endl;
}
