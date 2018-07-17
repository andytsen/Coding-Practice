#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>& list, int cur, int b) {
    if(cur == b) { 
        list.push_back(cur);
        return true; 
    }
    if(cur > b) { return false; }
    
    list.push_back(cur);
    if(dfs(list, cur * 2, b)) {
        return true;
    }
    if(dfs(list, (cur * 10) + 1, b)) {
        return true;
    }
    list.pop_back();
    return false;
}

int main() {
    int a,b;
    cin >> a >> b;

    vector<int> cur;
    dfs(cur,a,b);
    
    cout << cur.size() << endl;
    for(int i : cur) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
