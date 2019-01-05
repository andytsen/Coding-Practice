
#include <stack>
#include <vector>
#define abs(a) (a < 0 ? (a * -1) : a)

using namespace std;

void reverse(stack<int>& stk) {
    stack<int> tmp;
    while (!stk.empty()) {
        tmp.push(stk.top());
        stk.pop();
    } 
    stk = tmp;
}

vector<int> collide(vector<int>& asteroids) {
    stack<int> pos;
    stack<int> neg;
    for (int a : asteroids) {
        if (a < 0) {
            neg.push(a);
            while (!pos.empty()) {
                int atop = pos.top();
                if(atop < abs(a)) {
                    pos.pop();
                }
                else {
                    neg.pop();
                }
            }
        } 
        else {
            pos.push(a);
        }
    }

    vector<int> res;
    reverse(pos);
    reverse(neg);
    while(!neg.empty()) {
        res.push_back(neg.top());
        neg.pop();
    }
    while(!pos.empty()) {
        res.push_back(pos.top());
        pos.pop();
    }
    return res;
}

int main() {
    
}
