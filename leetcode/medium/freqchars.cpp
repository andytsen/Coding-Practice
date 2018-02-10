#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// rearrange string chars by freq
string frequencySort(string s) {
    unordered_map<char,int> m;
    priority_queue<pair<int,char>> char_pq;
    string ans = "";
    for(char c : s) {
        m[c]++;
    }
    unordered_map<char,int>::iterator it = m.begin();
    while(it != m.end()) {
        char_pq.push(pair<int,char>(it->second, it->first));
        ++it;
    }
    while(!char_pq.empty()) {
        pair<int,char> p = char_pq.top();
        for(int i = 0; i < p.first; i++) {
            ans += p.second;
        }
        char_pq.pop();
    }
    return ans;
}


int main() {
    string s = "lorem ipsum is a great phrase";
    cout << frequencySort(s) << endl;
    return 0;
}


