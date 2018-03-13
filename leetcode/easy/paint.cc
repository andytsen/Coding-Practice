// Paint House in Leetcode
// Andy Tseng 
// 3/12/18

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int findMin(std::vector<int>& row) {
    int res = INT_MAX;
    for(int r : row) {
        if(res > r) {
            res = r;
        }
    }
    return res;
}

// similar to seam carving algorithm, uses min cost matrix to find smallest path
int minCost(std::vector<std::vector<int>>& costs) {
    if(costs.size() == 0) { return 0; }
    if(costs.size() == 1) { 
        return findMin(costs[0]);
    } 
    else {
        for(int i = 1; i < costs.size(); ++i) {
            costs[i][0] += std::min(costs[i-1][1], costs[i-1][2]);
            costs[i][2] += costs[i-1][1];
            costs[i][1] += std::min(costs[i-1][0], costs[i-1][2]);
        }
    }
    return findMin(costs[costs.size() - 1]);
}

int main() {
    std::vector<std::vector<int>> costs;
    costs.push_back(std::vector<int>{7,1,12});
    costs.push_back(std::vector<int>{7,6,2});
    costs.push_back(std::vector<int>{1,40,12});
    cout << minCost(costs) << endl;
    return 0;
}
