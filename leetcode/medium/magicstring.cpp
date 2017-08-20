#include <iostream>

using namespace std;

int magicalString(int n) {
    string magic = "1";
    bool onOne = false;
    int ans = 1;
    int curptr = 1;
    while(magic.size() < n) {
        int bound = magic[curptr] == '1' ? 1 : 2;
        char to_add = onOne ? '1' : '2';
        for(int i = 0; i < bound; ++i) {
            magic += to_add;
            if(to_add == '1' && magic.size() <= n) // now allows 1 pass
                ans++;
        }
        curptr++;
        onOne = !onOne; // from '1' to '2' or vice-versa
    }
    // cout << magic << endl;
    //         for(int i = 0; i < n; i++) {
    //                     if(magic[i] == '1')
    //                                     ans++;
    //                                             }
    return ans;
}

int main() {
    cout << "Test 1 output : " << magicalString(6) << endl;
    cout << "Result 1 output should be 3" << endl;
    return 0;
}
