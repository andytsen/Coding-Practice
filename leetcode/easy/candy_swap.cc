#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> swap(vector<int>& alice, vector<int>& bob) {
    unordered_map<int,int> bvals;
    int suma = 0;
    int sumb = 0;
    for(int i = 0; i < alice.size(); ++i) { 
        suma += alice[i]; 
    }
    for(int i = 0; i < bob.size(); ++i) { 
        bvals[bob[i]] = 1;
        sumb += bob[i]; 
    }
    int diff = sumb - suma;

    for(int i = 0; i < alice.size(); ++i) {
        int bneed = (diff + (2 * alice[i]))/2;
        if(bvals[bneed] == 1) {
            vector<int> res;
            res.push_back(alice[i]);
            res.push_back(bneed);
            return res;
        }
    } 
    // an answer exists. but lets do a case where it doesn't, unrealistic.
    vector<int> fake;
    fake.push_back(-1);
    fake.push_back(-1);
    return fake;
}

int main() {
    vector<int> a = {1,1};
    vector<int> b = {2,2};
    vector<int> res = swap(a,b);
    cout << "[ ";
    for(int i = 0; i < res.size(); ++i) { cout << res[i] << " "; }
    cout << "] " << endl
        ;
    vector<int> a2 = {1,2,5};
    vector<int> b2 = {2,4};
    vector<int> res2 = swap(a2,b2);
    cout << "[ ";
    for(int i = 0; i < res2.size(); ++i) { cout << res2[i] << " "; }
    cout << "] " << endl;
}
