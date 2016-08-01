#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,d;
    cin >> n >> d;
    string a;
    int max = 0;
    int days = 0;
    for(int i = 0; i < d; i++)
    {
        cin >> a;
        if(a.find('0') != -1) // 0 is there
        {
            days++;
        }
        else 
        {
            if(days > max)
            {
                max = days;
            }
            days = 0;
        }
    }
    if(days > max)
        max = days;
    cout << max << endl;
    return 0;
}
