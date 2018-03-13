// Degree of an Array 
// Andy Tseng
// 3/12/18

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int,int> vals;
    for(int i : nums) { vals[i]++; }
    int max_freq = INT_MIN;
    int num = 0;
    for(pair<int,int> i : vals) {
        if(max_freq < i.second) {
            num = i.first;
        }
    }
    return num;
}
int main() {
    vector<int> v1 = {1,2,2,3,1};
    cout << findShortestSubArray(v1) << endl;
    return 0;
}
