#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    /* What is this vector bug */
    int n;
    cin >> n;
    vector<int> list;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        list.push_back(a);
    }
    sort(list.begin(), list.end());

    int min = list.at(0);
    int wrong = 0;
    vector<int>::iterator it = list.begin();
    for(it = list.begin(); it != list.end(); ++it)
    {
        if(*it != min && wrong != 1)
        {
            min = *it;
            wrong = 1;
        }
    }

    if(wrong)
        cout << min << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
