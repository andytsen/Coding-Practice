#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int M,Q;
    cin >> M >> Q;
    vector<pair<int,int> > counts;
    for(int i = 0; i < M; ++i) {
        int start, end;
        cin >> start >> end;
        if(start < end) {
            counts.push_back(pair<int,int>(start,end));
        }

    }

    sort(counts.begin(), counts.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first > b.first; });
    for(int i = 0; i < Q; ++i) {
        int q;
        cin >> q;
        int c = 0;
        for(pair<int,int> p : counts) {
            if(q >= p.first && q < p.second) {
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}
