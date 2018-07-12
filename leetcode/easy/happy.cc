#include <iostream>

using namespace std;

int iter(int n) {
    int res = 0;
    while(n) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

bool happy(int n) {
    int slow = n;
    int fast = iter(n);
    while(slow != fast) {
        slow = iter(slow);
        fast = iter(iter(fast));
        if(slow == 1) return true;
    }
    return false;
}

int main() {
    cout << happy(19) << endl;
    return 0;
}
