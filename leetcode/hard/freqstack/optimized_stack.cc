// Andy Tseng
// Optimized from stack.cc which was O(1) push, O(n) pop
// Inspired from user lee215 on Leetcode. 

// His idea is to have a map that corresponds frequency counts to a stack. 
// Another map that maps values to counts for pushing/checking which stack to look
// at the previously mentioned map. 
// The improvement is from a O(n) pop runtime to a O(1) pop RT.

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class FreqStack {
    unordered_map<int, stack<int>> freq_to_stk;
    unordered_map<int,int> val_to_count;
    int highest;

    public:
        FreqStack() : highest(0) {}

        void push(int);
        int pop();
};


// some clean code practice down here. 

void FreqStack :: push(int value) {
    val_to_count[value]++;
    int c = val_to_count[value];
    if(c > highest) highest++;

    auto it = this->freq_to_stk.find(c);
    if(it == freq_to_stk.end()) {
        stack<int> s;
        s.push(value);
        freq_to_stk[c] = s;
    } else {
        freq_to_stk[c].push(value);
    }
}

int FreqStack :: pop() {
    stack<int> s = freq_to_stk[highest];
    int tmp = s.top();
    val_to_count[tmp]--;
    s.pop();
    highest--;
    return tmp;
}


int main() {
    FreqStack fs;

    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);

    cout << "SHOULD BE 5 " << fs.pop() << endl;
    cout << "SHOULD BE 7 " << fs.pop() << endl;

    return 0;
}

