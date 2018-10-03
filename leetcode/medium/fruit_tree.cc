// Leetcode: https://leetcode.com/problems/fruit-into-baskets/description/
// Andy Tseng

#include <iostream>
#include <vector>

using namespace std;

int total_fruit(vector<int>& trees) {
    int n1;
    int n1ptr = 0;
    int n2;
    int n2ptr;
    int right = -1;
    int i = 0;
    int res = 0;
    while(i < trees.size()) {

        if(n1 == -1) {
            n1 = trees[i];
            n1ptr = i;
            n2ptr = i;
            i++;
        }
        else if(trees[i] != n1 && n2 == -1) {
            n2 = trees[i];
            n2ptr = i;
            i++;
            right++;
        }
        else if(trees[i] != n1 && trees[i] != n2) {
            res = max(res, right - n1ptr + 1);
            i = n2ptr;
            n1 = -1;
            n2 = -1;
        } else {
            i++;
            right++;
        }
        
    }
    res = max(res, right - n1ptr + 1);
    return res;
}

int main() {
    vector<int> v1 = {1,2,1,1};
    cout << total_fruit(v1) << endl;
    vector<int> v2 = {1,0,3,4,3};
    cout << total_fruit(v2) << endl;
    vector<int> v3 = {0,1,6,6,4,4,6};
    cout << total_fruit(v3) << endl;
}
