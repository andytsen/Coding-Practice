#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> parse(string s) {
    size_t plus = s.find("+");
    size_t i_index = s.find("i");
    int a = stoi(s.substr(0,plus));
    int b = stoi(s.substr(plus+1, i_index));
    return vector<int>{a,b};
}

string complexNumberMultiply(string a, string b) {
    string ans = "";
    vector<int> nums_a = parse(a);
    vector<int> nums_b = parse(b);
    ans += to_string((nums_a[0] * nums_b[0]) + (nums_a[1] * nums_b[1] * -1));
    ans += "+";
    ans += to_string((nums_a[1] * nums_b[0]) + (nums_a[0] * nums_b[1]));
    ans += "i";
    return ans;
}

int main() {
   cout << complexNumberMultiply("1+-1i", "1+1i") << endl;
}
