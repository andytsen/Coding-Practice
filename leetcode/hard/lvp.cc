// longest valid parenthesis
// Andy Tseng

#include <string>
#include <iostream>
#define max(a,b) ((a > b) ? (a) : (b))
#define rep(i,n) for(int i = 0; i < n; ++i)

using namespace std;

int stack[65536];

int valid_paren(string s)  {
    int res = 0; 
    int top = 0;
    int start = -1;

    rep(i,s.size()) {
        if(s[i] == '(') {
            stack[top++] = i; 
        } else if(top <= 0) {
            start = i;
        } else {
            res = max(res, 
        }
    }     
}

int main() {
    valid_paren("(()())");
    return 0;
}
