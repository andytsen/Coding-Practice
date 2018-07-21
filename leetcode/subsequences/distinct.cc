// 115 Distinct subsequence
// Andy Tseng

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& memo, string s, string t, int sptr, int tptr) {
    if(tptr == t.size()) {
        return 1;
    }
    if(sptr >= s.size()) {
        return 0;
    }
    if(memo[sptr][tptr] != 0) { return memo[sptr][tptr]; }

    int res = dfs(memo, s, t, sptr + 1, tptr);
    if(s[sptr] == t[tptr]) {
        res += dfs(memo, s, t, sptr + 1, tptr + 1);
    }
    memo[sptr][tptr] = res;

    return res;
}

int distinctss(string s, string t) {
    if(t.size() > s.size()) return 0;
    vector<vector<int>> dp = vector<vector<int>>(s.size(), vector<int>(t.size(), 0));
    return dfs(dp,s,t,0,0); 
}


int main() {
    cout << distinctss("rabbbit", "rabbit") << endl;
    cout << distinctss("babgbag", "bag") << endl;

    return 0;
}
