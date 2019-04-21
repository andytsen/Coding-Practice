// leetcode: https://leetcode.com/problems/camelcase-matching/
// Andy Tseng

#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool match(string query, string pattern) {
    int pat_index = 0;
    for (int i = 0; i < query.size(); ++i) {
        if (query[i] != pattern[pat_index]) {
           if (query[i] >= 'A' && query[i] <= 'Z') {
                return false;
           } 
        } else {
            pat_index++;
        }
    }

    if(pat_index < pattern.size()) {
        return false;
    }
    return true;
}

vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> res;
    for (string query : queries) {
        res.push_back(match(query, pattern));
    } 
    return res;
}

int main() {

}


