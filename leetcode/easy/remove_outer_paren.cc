// remove the outer most parenthesis of a string
// Leetcode https://leetcode.com/problems/remove-outermost-parentheses/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

string remove_outer_paren(string input) {
    int lvl = 0;
    stack<int> open_indexes;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(') {
            open_indexes.push(i);
            lvl++;
        }

        if (input[i] == ')') {
            if (open_indexes.empty()) {
                return "not valid string\n";
            }
            int top = open_indexes.top();
            open_indexes.pop();
            lvl--;
            if (lvl == 0) {
                input[i] = '-';
                input[top] = '-';
            }
        }
    }

    string res = "";
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] != '-') {
            res += input[i];
        }
    }
    return res;
}

int main() {
    cout << "\"" << remove_outer_paren("()()") << "\"" << endl;
    cout << "\"" << remove_outer_paren("(())") << "\"" << endl;
    return 0;
}
