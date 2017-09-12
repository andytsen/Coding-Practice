#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// longest substring of string s
int longest_ss(string s) {
    if(s.size() < 2) return s.size();
    unordered_map<char,int> m;
    int p1 = 0;
    int p2 = 0;
    int max_len = 0;
    while(p2 < s.size()) {
        if(m.find(s[p2]) != m.end()) {
            p1 = max(p1, m[s[p2]] + 1);
        }
        m[s[p2]] = p2;
        max_len = max(max_len, p2 - p1 + 1);
        ++p2;
    }

    return max_len;
}

int main() {
    cout << longest_ss("abcaaccb") << endl;
}
