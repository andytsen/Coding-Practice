
#include <vector>
#include <iostream>

// tree stuff





// each edge has weight of 1
vector<vector<int>> makeGraph(int n, vector<pair<int,int> edges) {
    vector<vector<int>>& g = vector<vector<int>>(n, vector<int>(n, 0));
    for(pair<int,int> p : edges) {
        g[p.first][p.second] = 1;
    }
    return g;
}

int main() {
    // format of input file:
    // n = 5
    // edges = [ (1,2), (1,3), (2,4), (3, 5) ]

    vector<pair<int,int> e;
    e.push_back(pair<int,int>(1,2));
    e.push_back(pair<int,int>(1,3));
    e.push_back(pair<int,int>(2,5));
    e.push_back(pair<int,int>(3,5));
    e.push_back(pair<int,int>(1,4));
    vector<vector<int>> graph = makeGraph(5, e);
}



