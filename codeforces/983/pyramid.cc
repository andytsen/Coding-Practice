// XOR-pyramid 983B on Codeforces
// Link : http://codeforces.com/problemset/problem/983/B 
// Andy Tseng

#include <iostream>
#include <vector>
#include <algorithm>

#define rep(s,i,n) for(int i = s; i < n; ++i)

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp;
    vector<vector<int>> max_vals;
    vector<int> b = vector<int>(n,0);

    rep(0,i,n) {
        cin >> b[i];
    }
    dp.push_back(b);
    max_vals.push_back(b);

    for(int i = 0; i < n; ++i) {
        b = dp.back();
        vector<int>mb = max_vals.back();
        vector<int> tmp;
        vector<int> max_tmp;
        for(int j = 1; j < b.size(); ++j) {
            tmp.push_back(b[j] ^ b[j-1]);
            max_tmp.push_back(max(mb[j], max(mb[j-1], b[j] ^ b[j-1])));
        } 
        max_vals.push_back(max_tmp);
        dp.push_back(tmp);
    }

    /*
    for(vector<int> v : dp) {
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
 
    for(vector<int> v : max_vals) {
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    */
       
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << max_vals[r-l][l-1] << endl;        
    }
    return 0;
}
