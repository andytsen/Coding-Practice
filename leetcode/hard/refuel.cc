// Leetcode: https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
// Andy Tseng


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dfs(int target, int cur, vector<vector<int>>& stations, vector<int>& visited) {
    if(cur >= target) return 0;

    int res = INT_MAX;
    for(int i = 0; i < stations.size(); ++i) {
        if(cur >= stations[i][0] && visited[i] == 0) {
            visited[i] = 1;
            res = min(dfs(target, cur + stations[i][1], stations, visited) + 1, res); 
            visited[i] = 0;
        }
    }
    return res;
}

int min_refuels(int target, int start, vector<vector<int>>& stations) {
    vector<int> visited = vector<int>(stations.size(),0); 
    int res = dfs(target,start,stations,visited);
    return res == INT_MAX ? -1 : res;
}

int main() {
    vector<vector<int>> stations;
    stations.push_back(vector<int>{10,60});
    stations.push_back(vector<int>{20,30});
    stations.push_back(vector<int>{30,30});
    stations.push_back(vector<int>{60,40});
    cout << min_refuels(100, 10, stations) << endl;


    vector<vector<int>> stations2;
    stations2.push_back(vector<int>{10,100});
    cout << min_refuels(100, 1, stations2) << endl;
}
