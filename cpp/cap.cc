// given an array of container weights, find the two containers that have the max capacity lower than the threshold

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

double findClosest(vector<double>& containers, int len, int start, double target) {
    int lo = start;
    int hi = len;
    int mid = 0;
    while (lo < hi) {
        mid = lo + (hi - lo >> 1);
        if(containers[mid] == target) { 
            return containers[mid];
        } else if (containers[mid] > target) {
            if(mid - 1 > 0 && containers[mid - 1] <= target) {
                return containers[mid - 1]; 
            }
            hi = mid;
        } else {
            if(mid + 1 < len && containers[mid + 1] > target) {
                return containers[mid];
            }
            lo = mid + 1;
        }
    }
    return containers[mid];
}

pair<double,double> findCapacity(vector<double>& containers, double maxCapacity) {
    sort(containers.begin(), containers.end()); 
    int len = containers.size();
    double weight = 0.0;
    pair<double,double> res;
    for(int i = 0; i < len; ++i) {
        double diff = maxCapacity - containers[i]; 
        // do binary serach to look for the element closest to the diff
        double other = findClosest(containers, len, i, diff);
        if ((other + containers[i]) > weight && (containers[i] + other) <= maxCapacity) {
            weight = other + containers[i];
            res = pair<double,double>(other, containers[i]);
        }
    }
    return res;
}

int main() {
    vector<double> containers = {19, 1.5, 1, 3.5, 17.25 };
    pair<double,double> res = findCapacity(containers, 20.75);
    cout << res.first << " " << res.second << endl;
}
