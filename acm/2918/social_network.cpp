#include <iostream>
#include <string>

using namespace std;
int main() {
    int n;
    cin >> n;
    int max = 0;
    string max_str = "";
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int count = 0;
        for(int j = 0; j < s.size(); ++j) {
            if(s[j] == '4' || s[j] == '3' || s[j] == '_' || s[j] == '1' || s[j] == '0') {
                count++;
            }
        }
        if(count > max) {
            max = count;
            max_str = s;
        }
    }
    cout << max_str <<  " " << max << endl;    
    return 0;
}
