#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> combination(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;

    function<void(int)> func = [&](int val) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }
        if(val == n + 1) return;

        // choose the
        cur.push_back(val);
        func(val + 1);
        cur.pop_back();

        func(val + 1);
    }
    
}

int main() {

}
