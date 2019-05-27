// just some equations computation stuff
//
// Andy Tseng



#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int compute(string equation) {
    int cur = 0;
    char op = ' ';
    for(int i = 0; i < equation.size(); ++i) {
        if(equation[i] == '+' || equation[i] == '-') {
            op = equation[i];
        }
        else if(equation[i] >= '0' && equation[i] <= '9') {
            // create the number
            int num = 0;
            int j = i;
            while(equation[j] >= '0' && equation[j] <= '9') {
                num = (num * 10) + (equation[j] - '0');
                j++;
            }
            i = j;

            if(op == ' ') {
                cur = num;
            }
            else {
                cur = op == '+' ? cur + num : cur - num;
            }
        }
    }
    return cur;
}

bool is_number(string s) {
    for(auto c : s) {
        if(c < '0' || c > '9') {
            return false; 
        }
    }
    return true;
}

// 2 - 1 - 1 -> [2,0]
// 2 * 3 - 4 * 5 -> [-34, -14, -10, -10, 10]
vector<int> diff_compute(string equation) { 
    if (equation.size() == 0) {
        return {};
    }
    if (is_number(equation)) {
        return { stoi(equation) };
    }

    vector<int> sols;
    int end = equation.size() - 1; 
    for (int i = 0; i < equation.size(); ++i) {
        if (equation[i] >= '0' && equation[i] <= '9') 
            continue;
        vector<int> left = diff_compute(equation.substr(0,i));
        vector<int> right = diff_compute(equation.substr(i + 1));
        if(left.size() == 0 || right.size() == 0) continue;
        for(int l : left) {
            for(int r : right) {
                if(equation[i] == '+') sols.push_back(l + r);
                if(equation[i] == '-') sols.push_back(l - r);
                if(equation[i] == '*') sols.push_back(l * r);
            }
        }
    }

    return sols;
} 

void TEST_diff_compute(string eq) {
    cout << "==== TEST CASE ====" << endl;
    vector<int> v = diff_compute(eq);
    cout << eq << " = "; 
    cout << "[ ";
    for( int vi : v) {
        cout << vi << " ";
    }
    cout << "]" << endl;;
}


int main() {
    
    cout << "2 - 1 = " << compute("2 - 1") << endl;    
    cout << "12 + 1 - 10  = " << compute("12 + 1 - 10") << endl;    
    cout << "12 +-+-+ 1  = " << compute("12 +-+-+ 1") << endl;    
    
    TEST_diff_compute("2*3-4*5");
    TEST_diff_compute("4+1*10-12");
    return 0;
}
