#include <vector>
#include <iostream>

using namespace std;


// edges
// beauty
// curT
// curBeauty
int findBestPath(vector<vector<int>>& edges, vector<int>& beauty, int curT, int curBeauty, int curCity) {
    if(curT < 0) {
        return 0;
    }
    if(curT == 0) {
        return curBeauty;
    }

    int res = curBeauty;
    for(int i = 0; i < edges[curCity].size(); ++i) {
        if(i != curCity) {
            int nextCity = i;
            
        }
    }

}

// n = num cities
// m = num edges
// beauty = beauty value of each city
// travelTime = time it takes to get from city A to B
// maxT = max time you have to traverse
int findBestPath(int n, int m, vector<int>& u, vector<int>& v, vector<int>& beauty, vector<int> travelTime, int maxT) {
    vector<vector<int>> edges = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i = 0; i < m; ++i) {
        edges[u[i]][v[i]] = t[i];
    }


}
