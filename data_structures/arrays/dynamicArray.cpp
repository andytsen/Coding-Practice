#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n,q;
    cin >> n >> q;
    int lastAns = 0;
    vector <vector<int> > seqList(n);
    
    for(int i = 0; i < q; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1)
        {
            int seq = (x^lastAns) % n;
            seqList[seq].push_back(y);
        }
        else if(type == 2)
        {
            int seq = (x^lastAns) % n;
            int index = y % seqList[seq].size();
            lastAns = seqList[seq][index];
            cout << lastAns << endl;
        }
    }

    return 0;
}
