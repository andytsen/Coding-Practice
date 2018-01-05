#include <vector>

using namespace std;
bool can_finish(int num, vector<pair<int,int>>& pre_reqs) {
    vector<vector<bool>> adj_matrix = vector<vector<bool>>(num, vector<bool>(num, false));
    for(pair<int,int> p : pre_reqs) {
        adj_matrix[p.first][p.second] = true;
    }
    return false;
}
