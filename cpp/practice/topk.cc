// quick practice on maps and pq
//
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

vector<string> topk(vector<string> words, int k);

int main() {
    vector<string> ss = {"love", "i", "i", "love", "love", "words", "imls" };
    vector<string> v1 = topk(ss,2);
    
    for(string v : v1) { cout << v << " "; }
    return 0;
}

vector<string> topk(vector<string> words, int k) {
    map<string,int> m;
    vector<string> res;
    for(string s : words) {
        m[s]++;
    }
    vector<pair<string,int>> list;
    map<string,int> :: iterator it = m.begin();
    while(it != m.end()) {
        list.push_back(pair<string,int>(it->first,it->second));
        ++it;
    }
    sort(list.begin(), list.end(), [](pair<string,int> a, pair<string,int> b) {
        if(a.second == b.second) { return a.first < b.first; }
        else { return a.second > b.second; }
    });
    for(int i = 0; i < k; ++i) {
        res.push_back(list[i].first);
    }
    return res;
}
