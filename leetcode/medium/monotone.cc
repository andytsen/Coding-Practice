// Andy Tseng
// https://leetcode.com/problems/monotone-increasing-digits/description/
// Monotone Increasing Digits

#include <iostream>
#include <vector>

using namespace std;

int find_monotone(int n) {
    vector<int> digits;
    while(n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    for(int i : digits) { cout << i << " "; } 


}

int main() {
    find_monotone(332);
}
