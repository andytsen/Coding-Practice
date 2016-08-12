#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int p = 1;
    for(int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        if(ai >= p)
            p++;
    }
    cout << p << endl;
    return 0;
}
