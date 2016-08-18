#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    for(int i = 1; i <= a - 1; i++)
    {
        if(i % 2 == 1)
        {
            cout << "I hate that ";
        }
        else
        {
            cout << "I love that ";
        }
    }
    if(a % 2 == 1)
        cout << "I hate it" << endl;
    else
        cout << "I love it" << endl;
    return 0;
}
