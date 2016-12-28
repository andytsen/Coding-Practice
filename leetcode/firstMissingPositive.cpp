#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>);

int firstMissingPositive(vector<int> a) {
    int i = 0;
    while(i < a.size()) {
        if(a[i] > 0 && a[i] <= a.size() && a[i] != a[a[i] - 1])
            swap(a[i], a[a[i] - 1]);
        else i++;
    }
    print_vector(a);
    return 0;
}

void print_vector(vector<int> nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a = {3,2, -1, 9, 1};
    firstMissingPositive(a);
    return 0;
}


