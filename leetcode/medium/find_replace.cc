// leetcode: https://leetcode.com/problems/find-and-replace-pattern/description/
// Andy Tseng

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> find(vector<string>& words, string pattern) {
    vector<string> res;
    for(string w : words) {
        if(w.size() == pattern.size()) {
            unordered_map<char,char> l2r;
            unordered_map<char,char> r2l;
            bool valid = true;
            for(int i = 0; i < pattern.size(); ++i) {
                if(l2r.count(pattern[i]) > 0) {
                    if(l2r[pattern[i]] != w[i]) valid = false;
                } else if(r2l.count(w[i]) > 0) {
                    if(r2l[w[i]] != pattern[i]) valid = false;
                } else {
                    l2r[pattern[i]] = w[i];
                    r2l[w[i]] = pattern[i];
                }
            }
            if(valid) res.push_back(w);
        }
    }
    return res;
}


int main() {
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    vector<string> res = find(words, "abb");
    for(string s : res) { cout << s << " "; }
    cout << endl;
}
