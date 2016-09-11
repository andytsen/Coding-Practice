#include <iostream>
#include <string>
#include <map>
using namespace std;

long factorial(int n)
{
    long res = 1L;
    for(int i = 0; i < n; i++)
    {
        res *= n - i;
    }
    return res;
}
int main() 
{
    string a;
    cin >> a;
    map<char,int> mp;
    map<char,int> :: iterator it;
    // find repeats
    for(int i = 0; i < a.length(); i++)
    {
        if(mp.count(a.at(i)) > 0)
        {
            mp[a.at(i)]++;
        }    
        else
        {
            mp.insert(pair<char,int> (a.at(i), 1));
        }
    }
    int den = 1;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        den *= factorial(it->second);
    }
    cout << factorial(a.length())/den << endl;
    return 0;
}
