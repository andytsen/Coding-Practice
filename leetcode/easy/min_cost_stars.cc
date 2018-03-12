#include <iostream>
#include <vector>

using namespace std;
int min_cost_stairs(vector<int>& vals) {
    vector<int> dp(vals.size() + 1);
    vals.push_back(0);
    dp[0] = vals[0];
    dp[1] = vals[1];
    for(int i = 2; i < dp.size(); ++i) {
        dp[i] = vals[i] + min(dp[i - 1], dp[i - 2]);
    }
    return dp[dp.size() - 1];
}

int main() {
    vector<int> t1 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << min_cost_stairs(t1);
    cout << endl;
    vector<int> t2 = {10, 15, 20};
    cout << min_cost_stairs(t2) << endl;
    return 0;
}
