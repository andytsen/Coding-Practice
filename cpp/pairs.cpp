#include <iostream>
using namespace std;

int main() {
    pair<int,int> a = pair<int,int>(1,2);
    cout << a.first << " " << a.second << " " << endl;
    a.first = 0;
    cout << a.first << " " << a.second << " " << endl;
    return 0;

}
