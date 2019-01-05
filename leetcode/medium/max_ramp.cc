#include <algorithm>
#include <vector>

#define min(a,b) ( a < b ? a : b)
#define max(a,b) ( a > b ? a : b)


using namespace std; 

// leetcode: 

int maxRamp(vector<int>& arr) {
    int maxWidth = 0;
    int minIndex = arr.size() + 1;
    vector<pair<int,int>> indexes;
    for(int i = 0; i < arr.size(); ++i) {
       indexes.push_back(pair<int,int>(arr[i],i)); 
    }
    sort(indexes.begin(), indexes.end(), [](pair<int,int>& a, pair<int,int>& b) {
        return a.first < b.first;
    });

    for(int i = 0; i < indexes.size(); ++i) {
        maxWidth = max(maxWidth, indexes[i].second - minIndex);
        minIndex = min(minIndex, indexes[i].second); 
    }
    return maxWidth;
}
