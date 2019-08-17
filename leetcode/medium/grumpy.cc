// https://leetcode.com/problems/grumpy-bookstore-owner/
// Andy Tseng


#include <vector>
#include <iostream>

#define max(a,b) ((a > b) ? a : b)

using namespace std;

int max_satisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int max = 0;
    int add = 0;
    for(int i = 0; i < X; ++i) {
        if(grumpy[i] == 1) {
            add += customers[i];
        }
        else {
            max += customers[i];
        }
    }

    int cur = add;  
    for(int i = 1; i < customers.size() - X + 1; ++i) {
        cur -= grumpy[i - 1] == 1 ? customers[i-1] : 0;
        cur += grumpy[i + X - 1] == 1 ? customers[i + X - 1] : 0;
        add = max(add,cur);
        max += grumpy[i + X - 1] == 0 ? customers[i + X - 1] : 0;
    }
    
    
    return max + add;
}


int main() {
    vector<int> c1 = {1,0,1,2,1,1,7,5};
    vector<int> g1 = {0,1,0,1,0,1,0,1};
    cout << "==============================================================" << endl;
    cout << "input = c1 = {1,0,1,2,1,1,7,5}, g1 = {0,1,0,1,0,1,0,1}, X = 3" << endl;
    cout << max_satisfied(c1,g1,3) << endl;
    cout << "==============================================================" << endl;





    return 0;
}
