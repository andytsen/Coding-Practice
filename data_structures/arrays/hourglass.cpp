#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    int a[6][6];
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cin >> a[i][j];
        }
    }

    int max = INT_MIN;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int val = a[i][j] + a[i+2][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1] + 
                a[i+2][j+1] + a[i+2][j+2];
            if(max < val)
                max = val;
        }
    }
    cout << max << endl;
    return 0;
}
