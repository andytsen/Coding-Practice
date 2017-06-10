#include <vector>
#include <iostream>
using namespace std;

int maxCount(int,int,vector<vector<int>>&);

int main() {
    vector<vector<int>> a(2, vector<int>(2,0));
    cout << maxCount(3,3,a);
    return 0;
}

int maxCount(int n, int m, vector<vector<int>>& ops) {
    vector<vector<int>> values = vector<vector<int>>(m, vector<int>(n,0));
    int maximum = ops.size();
    int ans = 0;
    for(vector<int> setop : ops) {
        int a = setop[0];
        int b = setop[1];
    }
    return ans;

}


