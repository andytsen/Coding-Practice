// strobgasdfkljskdf on leetcode
// Andy Tseng 3/15/18

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std; // convenience


// evaluates if the sum is strobgrammatic
bool strobgramm(string num) {
    unordered_map<char,char> map;
    map.insert(pair<char,char>('0','0'));
    map.insert(pair<char,char>('1','1'));
    map.insert(pair<char,char>('8','8'));
    map.insert(pair<char,char>('6','9'));
    map.insert(pair<char,char>('9','6'));
    string ans = "";
    for(int i = 0; i < num.size(); ++i) {
        if(map.find(num[i]) == map.end()) { return false; }
        else {
            ans = map[num[i]] + ans;
        }  
    }
    return num.compare(ans) == 0;
}



int main() {
    string n;
    cin >> n;
    cout << boolalpha << strobgramm(n) << endl;
    return 0;
}
