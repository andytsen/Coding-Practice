#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int longest_recursive(vector<int>& a);
int longest_dp(vector<int>& a);

int helper(vector<int>& a, int index, int res) {
    int local = 1;
    for(int i = index; i < a.size(); i++) {
        if(a[index] < a[i])
            local = max(helper(a, i, res + 1), local);
    }
    return res;
}

int longest_recursive(vector<int>& a) {
   if(a.size() == 0) return 0;
   helper(a, 0, 1);
}
