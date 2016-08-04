#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() 
{
    string a;
    cin >> a;
    int n = a.length();
    string sym = "AHIMOoTUVvWwXxY";
    map <char,char> pairs;
    pairs.insert(pair<char,char> ('p','q'));  
    pairs.insert(pair<char,char> ('q','p'));  
    pairs.insert(pair<char,char> ('b','d'));  
    pairs.insert(pair<char,char> ('d','b'));  

    for(int i = 0; i < n; i++)
    {
        if(pairs.count(a[i]) > 0)
        {
            if(pairs[a[i]] != a[n-i-1]) 
            {
                cout << "NIE" << endl;
                return 0;
            }
        }
        else if(a[i] != a[n - i -1])
        {
            cout << "NIE" << endl;
            return 0;
        } 
        else if(sym.find(a[i]) == string::npos)
        {
            cout << "NIE" << endl;
            return 0;
        }
    }
    cout << "TAK" << endl;
    return 0;
}
