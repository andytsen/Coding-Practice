#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b)
{
    
    sort(a.begin(), 
         a.end(), 
        [](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0] || v1[1] > v1[2];
        });

    sort(b.begin(), 
         b.end(), 
        [](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0] || v1[1] > v1[2];
        });

    int a_ptr = 0;
    int b_ptr = 0;

    while (a_ptr < a.size() || b_ptr < b.size())
    {

    }
}
