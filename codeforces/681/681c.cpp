#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int m;
    cin >> m;
    vector <int> h;
    for(int i = 0; i < m; i++)
    {
        string op;
        cin >> op;
        if(op == "insert")
        {
            int d;
            cin >> d;
            h.push_back(d);
        } 
        else if(op == "getMin")
        {
            int d;
            cin >> d;
            int r = 0;
            for(int i = 0; i < h.size(); i++)
            {
                if(h.at(i) > d)
                {
                } 
                r++; 
            }
            h.push_back(d);
        }
        // removeMin
        else 
        {
            if(!h.empty())
                h.erase(h.begin()); 
        }
        sort(h.begin(), h.end());
    } 
    return 0;
}
