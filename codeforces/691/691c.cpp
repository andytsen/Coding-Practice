#include <iostream>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int pos = 0;
    for(int i = 0; i < (int)a.size(); i++)
    {
        char c = a.at(i);
        if(c != '0' || c != '.')
        {
            pos = i;
            break;
        }
    } 
    size_t dot_ind = a.find('.');
    if(dot_ind == string::npos)
        dot_ind = a.size();
    int e = (int)(dot_ind - pos - 1);
    
    return 0;
}
