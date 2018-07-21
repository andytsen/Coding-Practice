
// testing something
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<vector<int>> res;
    vector<int> tmp = res[0];
    tmp.push_back(1);
    
    for(int i : tmp) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
