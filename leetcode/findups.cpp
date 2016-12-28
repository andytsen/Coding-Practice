#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> nums);

vector<int> find_dups(vector<int> nums) {
    vector<int> res;
    int i = 0;
    while (i < nums.size()) {
        cout << nums[i] << " " << nums[nums[i] - 1] << endl;
        print_vector(nums);
        if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
        else i++;

    }
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) res.push_back(nums[i]);

    }
    return res;
}

void print_vector(vector<int> nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    find_dups(nums);
    return 0;
}
