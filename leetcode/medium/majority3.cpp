#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> majority_three(vector<int>&); //o(n) space
vector<int> majority_linear(vector<int>&); // o(1) space
void print_vector(vector<int>&);

int main() {
    vector<int> test1 = {1,2,2,2,3,3,3,3,2};
    vector<int> ans1 = majority_three(test1);
    print_vector(ans1);
    ans1 = majority_linear(test1);
    print_vector(ans1);
    return 0;
}

// o(n) space
// two iterates
vector<int> majority_three(vector<int>& nums) {
    unordered_map<int,int> candidates;
    for(int i : nums) {
        if(candidates.count(i) > 0) {
            candidates[i]++;
        }
        else {
            candidates.insert(pair<int,int>(i,1));
        }
    }
    int threshhold = nums.size()/3;
    vector<int> ans;
    for(pair<int,int> c : candidates) {
        if(c.second > threshhold) {
           ans.push_back(c.first);
        }
    }
    return ans;
}

// o(1) space
vector<int> majority_linear(vector<int>& nums) {
    int candidate1, candidate2;
    int count1, count2 = 0;
    vector<int> ans; //solution to return
    for(int i : nums) {
        if(i == candidate1) count1++;
        else if(i == candidate2) count2++;
        else {
            if(count1 > 0 && count2 > 0) {
                count1--;
                count2--;
            }
            else if(count1) {
                candidate2 = i; // why?
                count2 = 1; // make sense based on previous line.
            }
            else {
                candidate1 = i;
                count1 = 1;
            }
        }
    }

    vector<int> candidates;
    if(count1 > 0) candidates.push_back(candidate1);
    if(count2 > 0) candidates.push_back(candidate2);
    for(int i : candidates) {
        int count = 0;
        for(int j : nums) {
            if(j == i)
                count++;
        }
        if(count > nums.size()/3)
            ans.push_back(i);
    }
    return ans;
}

void print_vector(vector<int>& stuff) {
    for(auto a : stuff) {
        cout << a << " ";
    }
    cout << endl;
}
