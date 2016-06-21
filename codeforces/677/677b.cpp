#include <iostream>
using namespace std;

int main()
{
    int n, h, k;
    cin >> n >> h >> k;
    int foo[n];
    for(int i = 0; i < n; i++)
    {
        cin >> foo[i];
    }

    int time = 0;
    int r = 0;
    int idx = 0;
    while(idx < n)
    {
        if((foo[idx] + r) < h)
        {
            if((foo[idx] + r + foo[idx + 1]) < h)
            {
                
            }
        }
        else
        {

        }
    }


    return 0;
}
