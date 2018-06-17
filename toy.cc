#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> find_numbers(vector<int>& arr) {
    vector<int> res; 
    unordered_map<int,bool> values;
    if(arr.size() == 0) return  res;
    res.push_back(arr[0]);
    for(int i = 1; i < arr.size(); ++i) {
        if(arr[i] - arr[i-1] != 1 && values.find(arr[i]) == values.end()) {
            values[arr[i]] = true;
            res.push_back(arr[i]);
        }
    }
    return res;
}

int main() {
    vector<int> test1 = {1,4,7,8,23,23,25,19,10};
    vector<int> res = find_numbers(test1);
    for(int i : res) { cout << i << " "; }
    cout << endl;
    return 0;
}
