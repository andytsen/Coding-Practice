#include <vector>
#include <iostream>

using namespace std;

int min_triangle(vector<vector<int>>& triangle) {
    int num_rows = triangle.size();
    vector<int> dp(triangle[num_rows - 1]);
    return 0;
}

int main() {
    vector<vector<int>> t1 = { {2}, {3,4}, {5,1,8}, {9,4,6,2} };
    cout << min_triangle(t1) << endl;
    return 0;
}
