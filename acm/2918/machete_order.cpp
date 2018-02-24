#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_map<string, int> vals;
    for(int i = 0; i < n; ++i) {
        string s;
        int e;
        cin >> s >> e;
        vals[s] = e; 
    }
    int m;
    cin >> m;
    long int prod = 1;
    for(int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        prod *= vals[s];
    }
    cout << prod << endl;
    return 0;
}
