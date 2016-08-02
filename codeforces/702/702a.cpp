#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max = 0;
    int inc = 0;
    int prev = 0;
    for(int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        if(prev < cur) 
        {
           inc++; 
        }
        else 
        {
            if(max < inc)
                max = inc;
            inc = 1;
        }
        prev = cur;
    }
    if(max < inc)
    {
        max = inc;
    }
    cout << max << endl;
    return 0;
}
