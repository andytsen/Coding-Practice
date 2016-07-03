#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    int val;
    vector<int> edges;
};



int main() {
    int n,m;
    cin >> n >> m;
    vector<struct node> houses(n);
    vector<struct node>::iterator it; 
    vector<int>::iterator it2; 

    for(int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        struct node a;
        a.val = h;
        houses.insert(it, i, a);
    }

    for(int i = 0; i < m; i++)
    {
        int e1, e2;
        cin >> e1 >> e2;
        struct node h1 = houses.at(e1);
        struct node h2 = houses.at(e2);
        h1.edges.insert(it2,e2);
        h2.edges.insert(it2,e1);
    }

    int gone[n];
    
    return 0;
}
