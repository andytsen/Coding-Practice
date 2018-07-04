#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i = 1; i <= n; ++i) {
        int e;
        cin >> e;
        g[i-1][e-1] = 1;
        g[e-1][i-1] = 1;
    }
}

