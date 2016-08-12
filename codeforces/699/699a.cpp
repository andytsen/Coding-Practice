#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int n;
    int a;
    string dir;
    cin >> n >> dir;
    int indx = 0;
    int c = 0;
    while(cin >> a)
    {
        if(dir.at(indx) == 'R' && (dir.length() > indx && dir.at(indx+1) == 'L')) 
        {
            int b;
            cin >> b; 
            if(b - a == 2)
            {
                c++;
            }
        }
    }
    if(c == 0)
        c = -1;
    cout << c << endl;
    return 0;
}
