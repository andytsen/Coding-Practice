// 792 on leetcode
// Andy Tseng

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int matching(vector<string>& words, string s) {
    int res = 0; 
    for(const string word : words) {
        int word_index = 0;
        int cur_index = 0;
        int word_len = word.size();
        while(word_index < word_len && cur_index < s.size()) {
           if(word[word_index] == s[cur_index]) {
               word_index++;
           } 
           cur_index++;
        }
        if(word_index == word_len) {
            res++;
        }
    }
    return res;
}

int main() {
    vector<string> words = {"a", "bb", "acd", "ace"};
    cout << matching(words, "abcdeb") << endl;
    return 0;
}
