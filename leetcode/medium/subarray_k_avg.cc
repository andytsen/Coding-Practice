// Leetcode: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Andy Tseng


#include <vector>
#include <numeric>
#include <iostream>

using namespace std;


int num_of_subarrays(vector<int>& nums, unsigned int k, int avg)
{
    int total = accumulate(nums.begin(), nums.begin() + k, 0);
    int cur_avg = total;
    int count = (cur_avg/k) >= avg ? 1 : 0;
    for (size_t i = k; i < nums.size(); ++i)
    {
        cur_avg -= nums[i-k]; 
        cur_avg += nums[i];
        if (cur_avg/k >= avg)
        {
            count++;
        }
    }
    return count;
}

int main()
{

    std::cout << "=========================" << std::endl;
    vector<int> v = {2,2,2,5,5,5,8};
    std::cout << num_of_subarrays(v, 3, 4) << std::endl;
    std::cout << "=========================" << std::endl;
    vector<int> v1 = {11,13,17,23,29,31,7,5,2,3};
    std::cout << num_of_subarrays(v1, 3, 5) << std::endl;
    return 0;
}
