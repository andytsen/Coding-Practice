// leetcode: https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
// Andy Tseng

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int min_increments(vector<int>& arr) {
    unordered_set<int> numbers;
    int incs = 0;
    for(int ai : arr) {
       while(numbers.find(++ai) != numbers.end()) {
           incs++;
       }
       numbers.insert(ai);
    } 
    return incs;
}

int main() {

    vector<int> v1 = {1,2,2};
    if(min_increments(v1) == 1) {
        cout << "pass" << endl;
    } else { cout << "fail" << endl; }

    vector<int> v2 = {3,2,1,2,1,7};
    if(min_increments(v2) == 6) {
        cout << "pass" << endl;
    } else { cout << "fail" << endl; }
}
