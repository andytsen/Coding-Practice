#include <stack>
#include <vector>
#include <iostream>

using namespace std;



vector<int> getDaysWaited(vector<int>& temps) 
{

    // entries are <TEMP, DAY>
    stack<pair<int,int>> cands;
    vector<int> daysWaitedList;
    for(int i = temps.size() - 1; i >= 0; --i) 
    {
        while(!cands.empty() && temps[i] > cands.top().first) cands.pop(); 
        int days = cands.empty() ? 0 : cands.top().second - i;
        daysWaitedList.insert(daysWaitedList.begin(), days);
        cands.push(pair<int,int>(temps[i], i));
    }
    return daysWaitedList;
}

int main() 
{
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = getDaysWaited(temps);
    for(int i : res) cout << i << " ";
    cout << "\n";
}
