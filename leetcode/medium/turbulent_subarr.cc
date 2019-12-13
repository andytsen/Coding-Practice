#include <vector>

int max_turbulence(vector<int>& A)
{
    int start = 0;
    int index = 0;
    int ans = 0;
    int mode = -1;

    while (index < A.size() - 1)
    {

        ans = max(ans, index - start + 1);
        index++;
    }
    return ans;
}
