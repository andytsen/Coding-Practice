#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int flag = 0;
    char line[n];
    for(int i = 0; i < n; i++)
    {
        cin >> line[i];
    }

    char* sub = strchr(line, '1');           
    while(sub != NULL)
    {
        // sub - line + 1 = difference
    }    

    if(flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
