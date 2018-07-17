#include <iostream>
#include <string>
#define rep(i,s,n) for(int i = s; i < n; ++i)

using namespace std;

int main() {
    int n,d;
    cin >> n >> d; 
    string s;
    cin >> s;

    int curr = 0;
    while(curr < s.size()) {
        int next = curr;
        rep(i,curr,d + curr) {
            char point = curr < s.size() ? s[curr] : '.';
            if(point == '1') {
                next = i; 
            }
        } 
    }
}
