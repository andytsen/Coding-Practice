#include <vector>
#include <algorithm>

using namespace std;

int find_longest_chain(vector<pair<int,int>>& vals) {
    sort(vals.begin(), vals.end(), 
            [](pair<int,int> a, pair<int,int> b) {
                return a.first < b.first;
            }
        );
    vector<int> dp(1, vals.size());
    for(int i = 0; i < vals.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            dp[i] = max(dp[i], vals[j].second < vals[i].first ? dp[j] + 1 : dp[j]);
        }
    }
    return dp[vals.size() - 1];
}

int main() {
    return 0;
}

