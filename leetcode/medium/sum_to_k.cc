// find the max subarray that equals k
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int sum_to_k(vector<int> arr, int k);

int main() {
    // for debugging
    vector<int> test1 = {10,5,2,7,1,9};
    cout << "Res : " << sum_to_k(test1, 15) << endl;
    return 0;
}

int sum_to_k(vector<int> arr, int k) {
    unordered_map<int,int> counts;
    int res = 0;
    int sum = 0;
    counts[0] = -1;
    for(int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if(counts.find(sum) == counts.end()) {
            counts[sum] = i;
        }
        if(counts.find(sum - k) != counts.end()) {
            res = max(res, i - counts[sum-k]);
        }
    } 
    return res;
}

