#include <iostream>
#include <vector>

using namespace std;

int find_cycle(vector<int>& visited, vector<int>& edges) {
    for(int i = 0; i < edges.size(); ++i) {
        if(edges[i] != -1) {
           if(visited[edges[i]] == 1) {
                return 1;
           }
           else {
               visited[edges[i]] = 1;
               if(find_cycle(visited, edges) == 1) {
                   return 0;
               }
               visited[edges[i]] = 0;
           }
        } 
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        int m,n;
        cin >> n >> m;

        vector<int> edges(-1, n-1);
        vector<int> visited(0, n-1);
        int flag = 0;
        for(int j = 0; j < m; ++j) {
            int a1, a2;
            cin >> a1 >> a2;
            edges[a1] = a2;
        }

        if(find_cycle(visited,edges) == 1) {
            cout << "TOO BIG" << endl;
        } else {
            cout << "TOO SMALL" << endl;
        }
    }
    return 0;
}
