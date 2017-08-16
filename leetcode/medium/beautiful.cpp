#include <vector>
#include <iostream>
using namespace std;

int backtrack(vector<int>& list, vector<bool>& used) {
    if(list.size() == (used.size() - 1)) {
        return 1;
    } else {
        int amount = 0;
        for(int i = 1; i < used.size(); i++) {
            int j = list.size() + 1;
            if((i % j == 0 || j % i == 0) && !used[i]) {
                list.push_back(i);
                used[i] = true;
                amount += backtrack(list,used);
                used[i] = false;
                list.pop_back();
            }
        }
        return amount;
    }
}

int countArrangement(int n) {
    vector<int> list = vector<int>(0);
    vector<bool> used = vector<bool>(n+1,false);
    return backtrack(list,used);
}

int main() {
    cout << countArrangement(3) << " ";
    cout << endl;
    return 0;
}
