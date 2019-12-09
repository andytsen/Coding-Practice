// https://leetcode.com/problems/grumpy-bookstore-owner/
// Andy Tseng


#include <vector>
#include <iostream>
#include <algorithm>

#define max(a,b) ((a > b) ? a : b)

using namespace std;

int max_satisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int ans = 0;
    int gssi = -1; // grumpy spell start index
    int index = 0; 
    int tmp = ans;

    while (index < customers.size())
    {
        if (grumpy[index])
        {
            if (gssi == -1)
            {
                gssi = index;
            }
            while (index - gssi >= X)
            {
                if (grumpy[gssi])
                {
                    tmp -= customers[gssi];
                }
                gssi++; 
            }
        }
        else
        {
            ans += customers[index];
        }
        
        tmp += customers[index];
        ans = max(tmp,ans);
        index++;
    }
    return ans;
}


int main() {
    vector<int> c1 = {1,0,1,2,1,1,7,5};
    vector<int> g1 = {0,1,0,1,0,1,0,1};
    cout << "==============================================================" << endl;
    cout << "input = c1 = {1,0,1,2,1,1,7,5}, g1 = {0,1,0,1,0,1,0,1}, X = 3" << endl;
    cout << max_satisfied(c1,g1,3) << endl;
    cout << "==============================================================" << endl;

    vector<int> c2 = {9,10,4,5};
    vector<int> g2 = {1,0,1,1 };
    cout << "==============================================================" << endl;
    cout << max_satisfied(c2,g2,1) << endl;
    cout << "==================u===========================================" << endl;

    vector<int> c3 = {2,4,1,4,1};
    vector<int> g3 = {1,0,1,0,1};
    cout << "==============================================================" << endl;
    cout << max_satisfied(c3,g3,2) << endl;
    cout << "==================u===========================================" << endl;





    return 0;
}
