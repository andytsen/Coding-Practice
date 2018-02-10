#include <vector>
#include <algorithm>

using namespace std;

int delete_earn(vector<int>& vals) {
    vector<bool> dp(vals.size(), 0);
    sort(vals.begin(), vals.end());
    int ans = INT_MIN;
    int delete_val = 0;
    for(int i = 0; i < vals.size(); ++i) {
        int score = 0;
        for(int j = i; j < vals.size(); ++j) {
            if(dp[j] == 0 && vals[j] != delete_val - 1 && vals[j] != delete_val + 1) {
                score += vals[j];
                delete_val = vals[j]; 
                dp[j] = 1;
            }
        } 
        ans = max(score, ans);
    }
    return ans;
}

int main() {
    vector<int> t1 = {2,3,3,3,4,8};
    delete_earn(t1);
}
