// leetcode 967

#include <vector>

using namespace std; 

void dfs(vector<int>& nums, int N, int K, int cur) {
    if(N == 0) {
        nums.push_back(cur);
    }
    int lastDigit = cur % 10;
    int up = lastDigit + K; 
    int down = lastDigit - K;
    if(up < 10) {
        dfs(nums, N - 1, K, (cur * 10) + up);
    }
    if(down >= 0) {
        dfs(nums, N - 1, K, (cur * 10) + down);
    }
}

vector<int> digitsOfSameDiff(int N, int K) {
    vector<int> res;
    for(int i = 1; i <= 9; ++i) {
        dfs(res, N - 1, K, i);
    } 
    return res;
}

int main() {
    digitsOfSameDiff(3,7);
}
