#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    int n, q;
    cin >> n;
    vector <string> a;
    for(int i = 0; i < n; i++)
    {
        string b;
        cin >> b;
        a.push_back(b);
    }

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int occur = 0;
        string query;
        cin >> query; 
        for(int i = 0; i < n; i++)
        {
            if(query == a[i])
            {
                occur++;
            } 
        }
        cout << occur << endl;
    }
    return 0;

}
