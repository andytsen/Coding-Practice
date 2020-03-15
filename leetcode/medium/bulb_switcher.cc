#include <vector>
#include <unordered_map>

#include <iostream>

/*
 * [2,1,3,5,4] -> 3
 * [3,2,4,1,5] -> 2
 * [4,1,2,3] -> 1
 * [2,1,4,3,6,5] -> 3 
 */

using namespace std;

int num_times_all_blue(std::vector<int> light)
{
    int res = 0;
    int sum = 0;
    int index_sum = 0;
    for (int k = 0; k < light.size(); ++k)
    {
        sum += light[k];
        index_sum += (k+1);
        if (sum == index_sum)
        {
            res++;
        }
    }   
    return res;
}

int main()
{
    std::cout << num_times_all_blue({2,1,4,3,6,5}) << std::endl;
    std::cout << num_times_all_blue({4,1,2,3}) << std::endl;
}
