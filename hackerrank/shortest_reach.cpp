#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int a,b;
        cin >> a >> b;
        int adjacency[a][a];
        int list[a];
        for(int j = 0; j < b; j++)
        {
            int aj, bj;
            cin >> aj >> bj;
            adjacency[aj-1][bj-1] = 1;
            adjacency[bj-1][aj-1] = 1;
        } 
        int s;
        cin >> s;
        int index = 0;
         
    }
}
