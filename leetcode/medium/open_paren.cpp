#include <vector>
#include <stack>
#include <string>
#include <iostream>

void recur(std::vector<std::string>& ans, std::string cur, int l, int r, int n) {
    if(l == n && l == r) {
        std::cout << cur << std::endl;
        ans.push_back(cur);
    } else {
        if(l < n) recur(ans, cur + '(', l + 1, r, n);
        if(l > r) recur(ans, cur + ')', l , r + 1, n);
    }
}

std::vector<std::string> generate_parenthesis(int n) {
    std::vector<std::string> ans;
    recur(ans, "", 0,0,n);    
    return ans;
}

int main() {
    std::vector<std::string> s;
    s = generate_parenthesis(3);  
    return 0;
}
