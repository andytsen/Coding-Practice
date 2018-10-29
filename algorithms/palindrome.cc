#include <string>
#include <vector>
#include <iostream>

#define max(a,b) ((a > b) ? a : b)

using namespace std;


// find the longest palindrome substring in a string

string longest_palindrome(string input) {
    int n = input.size();
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) dp[i][i] = 1;

    int b = -1;
    int e = -1;
    int res = 0;
    for(int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if(i > 0 && input[i] == input[i-1]) {
            dp[i-1][i]  = 1;
        }
    }


    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return input.substr(b, b + res - 1);
}

int main() {
    cout << longest_palindrome("babad") << " = bb" << endl;
    cout << longest_palindrome("cbbbc") << " = cbbbc" << endl;
    return 0;
}

