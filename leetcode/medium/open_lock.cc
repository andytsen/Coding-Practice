#include <string>
#include <vector>
#include <climits>
#include <unordered_set>
#include <queue>

using namespace std;

int open_lock(vector<string>& deadends, string target) {
    unordered_set<string> deadend_set = unordered_set(deadends.begin(), deadends.end());    
    unordered_set<string> visited;
    if(deadend_set.count(target) > 0) {
        return -1;
    }
    queue<string> q;
    q.push("0000");
    int ans = 0;
    
    while(!q.empty()) {
        int tmp = q.size();
        ans++;
        while(tmp-- > 0) {
            string cur = q.front();
            if(cur == target) {
                return ans;
            }
            for(int i = 0; i < target.size(); ++i) {
                if(target[i] != cur[i]) {
                    for(int flip = -1; flip <= 1; flip+=2) {
                        string tmp = cur;
                        char t = (((tmp[i] - '0') + flip) % 10) + '0';
                        tmp[i] = t; 
                        if(visited.count(tmp) == visited.end()) { 
                            visited.push(tmp);
                            q.push(tmp); 
                        }
                    }
                }
            }
            q.pop();
        }
    }
    return -1;
}

int main() {
    vector<string> d1 = {
}



