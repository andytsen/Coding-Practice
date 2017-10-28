#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

int main() {
    map<int,char> regmap;
    regmap[1] = 'a';
    regmap[3] = 'c';
    regmap[2] = 'b';
    map<int,char>::iterator it;
    cout << "tree map" << endl;
    for(it = regmap.begin(); it!=regmap.end(); it++) {
        cout << it->first << " " << it->second << endl; 
    }

    unordered_map<int,char> umap;
    umap[1] = 'a';
    umap[3] = 'c';
    umap[2] = 'b';
    umap[4] = 'd';
    umap[6] = 'f';
    umap[5] = 'e';
    unordered_map<int,char>::iterator uit;
    cout << "hash map" << endl;
    for(uit = umap.begin(); uit != umap.end(); uit++) {
        cout << uit->first << " " << uit->second << endl; 
    }

    return 0;
}

//++a
int plusplusint(int& a) {
    a = a + 1;
    return a;
}

//a++
int intplusplus(int& a) {
    int tmp = a;
    a = a + 1;
    return tmp;
}
