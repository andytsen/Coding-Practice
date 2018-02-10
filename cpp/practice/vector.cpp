#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> a = {10,20,30,40,50,90};
    vector<int>::iterator low1 = lower_bound(a.begin(), a.end(), 40);
    vector<int>::iterator low2 = lower_bound(a.begin(), a.end(), 5);
    vector<int>::iterator low3 = lower_bound(a.begin(), a.end(), 100);
    cout << "low: " << (low1 - a.begin()) << endl;
    cout << "low: " << (low2 - a.begin()) << endl;
    cout << "low: " << (low3 - a.begin()) << endl;
    return 0;
}
