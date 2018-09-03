// Leetcode: leetcode.com/problems/bitwise-ors-of-subarrays/description/
// Andy Tseng


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// TIME: O(n^2) , n = num elements in given input
// SPACE: O(n^2), n same as above
// APPROACH: I chose to use dp with memoization using the recuring formula:
// grid[i][j] = grid[i][j-1] | arr[j] with grid[i][i] all intialized, since we
// are looking for distinct total XOR values in all subarray of the input. 


int xor_sub(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int,bool> distinct;
    vector<vector<int>> grid = vector<vector<int>>(n, vector<int>(n, 0));

    int res = 0;
    for(int i = 0; i < arr.size(); ++i) { 
        grid[i][i] = arr[i];
        if(distinct.find(arr[i]) == distinct.end()) {
            res++;
            distinct[arr[i]] = true;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            grid[i][j] = grid[i][j-1] | arr[j];
            if(distinct.find(grid[i][j]) == distinct.end()) {
                res++;
                distinct[grid[i][j]] = true;
            }
        }
    }

    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return res;

}

// Trying some optimizations
int xor_sub_opt(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int,bool> distinct;

    int res = 0;
    return res;
}

int main() {
    vector<int> v1 = {1, 2, 4};
    cout << "Answer = " << xor_sub(v1) << endl;
}
