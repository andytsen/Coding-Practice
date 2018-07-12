#include <vector>
#include <iostream>

using namespace std;

vector<int> arr_add(vector<int>& a, vector<int>& b) {
    vector<int> top = a.size() >= b.size() ? a : b;
    vector<int> bot = a.size() < b.size() ? a : b;
    vector<int> res;
    
    int carry = 0;
    int bot_index = bot.size() - 1;
    for(int i = top.size() - 1; i >= 0; --i) {
        int d = bot_index >= 0 ? bot[bot_index] : 0;
        int cur = (top[i] + d + carry) % 10;
        carry = (top[i] + d + carry) / 10; 
        auto it = res.begin();
        res.insert(it, cur);
        bot_index--;
    }
    return res;
}

int main() {
    vector<int> a = {1, 2, 5};
    vector<int> b = {1, 1, 7};
    vector<int> res = arr_add(a,b);
    cout << "[ ";
    for(int i : res) { cout << i << " "; }
    cout << "]" << endl;

    a = {1,2,4,2};
    b = {1,9};
    res = arr_add(a,b);
    cout << "[ ";
    for(int i : res) { cout << i << " "; }
    cout << "]" << endl;

    a = {1,2,4,2};
    b = {1,9};
    res = arr_add(a,b);
    cout << "[ ";
    for(int i : res) { cout << i << " "; }
    cout << "]" << endl;

    return 0;
}
