// Maximum Length Pair Chain on Leetcode
// Andy Tseng 3/13/18

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Find the longest chain of pairs such that (a,b) connects to (c,d) and b < c
// Sort by second number, greedy algorithm, where everytime you see a pair that has
// a largest first than your second you know it should be the next one. 
int longest_pair(vector<pair<int,int>>& chains) {
    // did it on the leetcode thing
}

int main() {
    vector<pair<int,int>> chains;
    chains.push_back(pair<int,int>(1,2));
    chains.push_back(pair<int,int>(1,3));
    chains.push_back(pair<int,int>(3,4));
    chains.push_back(pair<int,int>(1,6));
    chains.push_back(pair<int,int>(5,6));
    chains.push_back(pair<int,int>(10,11));
    chains.push_back(pair<int,int>(10,13));
    cout << longest_pair(chains) << endl;

    for(pair<int,int> p : chains) {
        cout << p.first << " " << p.second << endl;
    }
}
