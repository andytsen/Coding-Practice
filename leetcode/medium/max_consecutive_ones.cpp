#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int longest_ones(vector<int>& bits, int K)
{
    int index = 0;
    int start = 0;
    int zero_count = 0;
    int ans = 0;

    while(index < bits.size())
    {
        if (bits[index] == 0)
        {
            zero_count++;
        }   
        while(zero_count > K)
        {
            if(bits[start] == 0)
            {
                zero_count--;
            }            
            start++;
        }
        ans = max(ans, index - start + 1);
        index++;
    }
    return ans;

}

int main()
{
    vector<int> v1 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << longest_ones(v1, 3) << endl;

    vector<int> v2 = {1,1,1,0,0,0,1,1,1,1,0};
    cout << longest_ones(v2, 2) << endl;
    
    return 0;
}
