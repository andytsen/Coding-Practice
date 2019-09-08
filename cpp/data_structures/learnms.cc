// This is where I learn to use multi-set data structure in cpp

#include <set>
#include <iostream>
#include <vector>

using namespace std;

class Pokemon {
    int a;
    public:
        Pokemon(int v) : a(v) {}
};

int main() {

    multiset<int> ms = {5,16,21,80};
    for(auto it = ms.crbegin(); it != ms.crend(); ++it) {
        cout << *it << " ";
    } 
    cout << endl;

    // emplace
    ms.emplace(75);
    ms.emplace(55);

    for(auto it = ms.cbegin(); it != ms.cend(); ++it) {
        cout << *it << " ";
    } 
    cout << endl;

    // upper and lower
    auto upper = ms.upper_bound(18);
    cout << *upper << endl;
    auto lower = ms.lower_bound(18);
    cout << *lower << endl;

    // key comp
    multiset<int>::key_compare mycomp = ms.key_comp();
    auto it = ms.begin();
    if(mycomp(*it, 60)) {
        cout << "SOME SHIT" << endl;
    } else {
        cout << "SOME WELP" << endl;
    }

    vector<Pokemon> party;
    Pokemon p(2);
    party.push_back(p);
    party.emplace_back(3);

    return 0;
}
