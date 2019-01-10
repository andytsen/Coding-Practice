// evaluate(string)

#include <iostream>
#include <string>
#include <stack>

using namespace std;


int evaluate(string exp) {
    
}

int main() {
    string exp1 = "5+16-((9-6)-(4-2))";
    cout << exp1 << " = " << evaluate(exp1) << endl;
    if(evaluate(exp1) == 20) {
        cout << "unit test 1 pass\n";
    }
    
}
