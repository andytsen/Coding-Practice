#include <iostream>
#include <vector>

using namespace std;

int combination(vector<int>& nums, int tgt);

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    cout << combination(a, 3) << endl;
    return 0;
}

int combination(vector<int>& nums, int tgt) {
    vector<int> dp(tgt + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= tgt; i++) {
        for(int n: nums) {
            if(n <= i) {
                dp[i] += dp[i-n];
            }
        }
    }

    for(int i = 0; i < tgt + 1; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[tgt];
}
