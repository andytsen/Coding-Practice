// Leetcode: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
// Andy Tseng

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// find the longest fib ss
int longest_fibss(vector<int>& arr) {
    unordered_set<int> elements = unordered_set<int>(arr.begin(), arr.end());
    if(arr.size() < 3) return 0;
    int len = 3;
    for(int i = 0; i < arr.size(); ++i) {
        for(int j = i + 1; j < arr.size(); ++j) {
            int a = arr[i]; 
            int b = arr[j];
            int cur_len = 2;
            while(elements.count(b + a)) {
                int tmp = b + a; 
                a = b;
                b = tmp; 
                cur_len++;
            }
            len = max(cur_len,len);
        }
    }
    return len;
}

int main() {
    vector<int> v1 = {1,2,3,4,5,6,7,8}; 
    cout << longest_fibss(v1) << endl;
}
