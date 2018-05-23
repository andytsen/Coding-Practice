// 638 on leetcode

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int dot_prod(const vector<int>&, const vector<int>&);
int shopping_recurse(vector<int>&, vector<vector<int>>&, vector<int>&, int);
string serialize(const vector<int>&);


int main() {
    return 0;
}

int dot_prod(const vector<int>& price, const vector<int>& needs) {
    int res = 0;
    for(int i = 0; i < price.size(); ++i) {
        res = price[i] * needs[i];
    }
    return res;
}

int shopping_recurse(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int spending) {
    int res = dot_prod(price, needs); 
    if(res == 0) { return spending; }
    res += spending;
    for(vector<int> offer : special) {
        int flag = 1;
        for(int j = 0; j < offer.size() - 1; ++j) {
            if(needs[j] < offer[j]) {
                flag = 0;
            } 
        }
        if(flag == 1) {
            for(int j = 0; j < offer.size() - 1; ++j) {
                needs[j] -= offer[j];
            }
            res = min(res, shopping_recurse(price, special, needs, spending + offer[offer.size() - 1]));
            for(int j = 0; j < offer.size() - 1; ++j) {
                needs[j] += offer[j];
            }
        }
    }
    return res;
}

int shopping_memo(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<string,int>& memo) {
    int count = 0;
    for(int i : needs) { count += needs[i]; }
    if(count == 0) { return 0; }

    string key = serialize(needs);
    if(memo.count(key) > 0) {
        return memo[key];
    }

    int res = 0;
    res += dot_prod(price,needs);
    for(vector<int> offer : special) {
        int flag = 1;
        for(int j = 0; j < offer.size() - 1; ++j) {
            if(needs[j] < offer[j]) {
                flag = 0;
            } 
        }
        if(flag == 1) {
            for(int j = 0; j < offer.size() - 1; ++j) {
                needs[j] -= offer[j];
            }

            res = min(res, shopping_memo(price, special, needs, memo) + offer[offer.size() - 1]);
            memo[serialize(needs)] = res + offer[offer.size() - 1];

            // backtrack
            for(int j = 0; j < offer.size() - 1; ++j) {
                needs[j] += offer[j];
            }
        }
    }
    memo[serialize(needs)] = res;
    return res;
}

string serialize(const vector<int>& needs) {
    string key = "";
    for(int i : needs) {
        key += to_string(i);
        key += ",";
    }
    return key;
}

// memoization we do alot of recalculation when using recursion.
int shopping_offers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    // move things to list since vector doesnt support the keys in std::map 
    map<string, int> dp;

    return 0;
}

