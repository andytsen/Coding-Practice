#include <stack>
#include <iostream>


using namespace std;

bool is_valid(char* str) {
    int i = 0;
    stack<char> stk;
    while(str[i]) {
        if(str[i] == '(') {
            stk.push(str[i]);
        } else {
            if(stk.empty()) return false;
            stk.pop();
        }
        ++i;
    }
    return stk.empty() ? true : false;
}

int main() {
    cout << is_valid("()()(())") << endl;
    cout << is_valid("()())");
    return 0;
}
