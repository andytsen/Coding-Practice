#include <iostream>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            char a;
            cin >> a;
            if(a == 'M' || a == 'C' || a == 'Y')
            {
                cout << "#Color" << endl;
                return 0;
            }
        }
    }  
    cout << "#Black&White" << endl;
    return 0;
}
