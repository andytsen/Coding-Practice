// toycode that gets all subsequence of strings that are palindromes of at least
// size n


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool palindrome(string s) {
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

void dfs(vector<string>& res, string cur, string s, int index, int n) {
    if(cur.size() >= n && palindrome(cur)) {
        res.push_back(cur);
    }

    unordered_set<char> dups;
    for(int i = index; i < s.size(); ++i) {
        if(dups.find(s[i]) == dups.end()) {
            cur += s[i];
            dups.insert(s[i]);
            dfs(res, cur, s, i + 1, n);
            cur = cur.substr(0, cur.size() - 1);
        }
    }
}

vector<string> get_palindromes(string s, int n) {
    vector<string> res;
    if(s.size() < n) return res;
    dfs(res, "", s, 0, n);
    return res;
}


// iterative version, because I hate recursion
vector<string> get_palindromes_iter(string s, int n) {
    vector<string> res;
    if(s.size() < n) return res;

    res.push_back("");
    
    for(int i = s.size() - 1; i >= 0; --i) {
        const char cand = s[i];
        int len = res.size();
        unordered_set<string> dups;
        for(int j = 0; j < len; ++j) {
            string tmp = res[j];
            tmp = tmp + cand;

            if(dups.find(tmp) == dups.end()) {
                dups.insert(tmp);
                res.push_back(tmp);
            }
        }
    } 

    vector<string> real_res;
    for(string word : res) {
        if(word.size() >= n && palindrome(word)) {
            real_res.push_back(word);
        }
    }
    return real_res;
}



int main() {
    vector<string> res = get_palindromes_iter("acbbadc", 3);

    for(const string s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
