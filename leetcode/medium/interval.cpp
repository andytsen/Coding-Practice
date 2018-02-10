#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& interval_list) {
    vector<Interval> merged;
    sort(interval_list.begin(), interval_list.end(), [] (Interval a, Interval b) { return a.start > b.start; });
    merged.push_back(interval_list[0]);
    Interval cur = merged.back();
    for(Interval i : interval_list) {
        if(i.end < cur.end) {
            merged.push_back(i); 
        } else {
            cur.end = max(cur.end, i.end);
        }
    }
    return merged;
}
