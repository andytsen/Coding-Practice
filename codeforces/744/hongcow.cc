// 744A on codeforces
// Andy Tseng

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> graph = vector<vector<int>>(n, vector<int>(n,0));
    unordered_map<int,int> gov_cities;
    for(int i = 0; i < k; ++i) { 
        int ni;
        cin >> ni;
        gov_cities[ni-1] = 1; 
    }
    for(int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
    }
    
    int edges = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(gov_cities.find(i) != gov_cities.end() 
               && gov_cities.find(j) != gov_cities.end()
               && graph[i][j] == 0) 
            {
                cout << i << " " << j << endl;
                edges++; 
            }
        }
    }
    cout << edges << endl;
    return 0;
}
