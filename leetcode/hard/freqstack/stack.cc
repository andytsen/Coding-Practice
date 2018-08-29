// Leetcode : https://leetcode.com/problems/maximum-frequency-stack/description/
// Andy Tseng

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class FreqStack {
    unordered_map<int,int> counts;
    stack<int> stk; 

    public:
        FreqStack() {}

        void push(int val) {
            this->counts[val]++;
            this->stk.push(val);
        }

        int pop() {
            int largest = 0;
            auto it = counts.begin();
            while(it != counts.end()) {
                if(it->second > largest) {
                    largest = it->second;
                }
                ++it;
            }

            int res = -1;
            stack<int> tmp;
            while(!stk.empty()) {
                int v = stk.top();
                stk.pop();
                if(counts[v] == largest) {
                    counts[v] -= 1;
                    res = v;
                    break;
                } else {
                    tmp.push(v);
                }
            }
            while(!tmp.empty()) {
                stk.push(tmp.top());
                tmp.pop();
            }
            return res;
        }
};

int main() {
    FreqStack fs;
    fs.push(3);
    fs.push(1); 
    fs.push(3);
    fs.push(3);
    fs.push(5); 
    fs.push(5); 

    cout << " SHOULD BE 3 " << fs.pop() << endl;
    cout << " SHOULD BE 5 " << fs.pop() << endl;

    return 0;
}
