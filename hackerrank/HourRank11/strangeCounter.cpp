#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long cycle = 0L;
    long long cap = 0L;
    long long a;
    cin >> a;
    while(a > cap)
    {
        cap += pow(2,cycle) * 3;
        cycle++;
    }
    cout << cap - a + 1<< endl;
    return 0;
}
