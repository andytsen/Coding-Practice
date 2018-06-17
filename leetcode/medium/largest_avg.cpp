// 813 on Leetcode
// Andy Tseng

// At first I just checked for largest value and removed until I had 1 partition
// left. If only 1 partition is allowed, then the best average is the whole array.
// BUT.. then the values had to be subsequent of eachother. We cannot not tack
// on values that are not connected to eachother. Example..
//  [9 3 9 2 1] , K = 3 
//  This examples doesnt allow the following:
//      [9], [3,2,1], [9]
//
//  Thus more thought needs to be put into this...
//
//

#include <vector>
#include <iostream>

using namespace std;

double largest_avg(vector<int>& arr, int k) {
    return 0.0;
}

int main() {
       
    return 0;
}

