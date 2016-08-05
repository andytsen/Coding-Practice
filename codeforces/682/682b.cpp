#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int p = 0;
    vector <int> list;
    for(int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        list.push_back(ai);
    }
    sort(list.begin(), list.end());
    vector<int>:: iterator it;
    int i =0;
    for(it = list.begin(); it != list.end(); it++)
    {
        if(*it > p)
        {
            p++;
        } 
        i++;
    }
    cout << p + 1 << endl;
    return 0;
}
