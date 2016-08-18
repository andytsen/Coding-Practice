#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        v.push_back(a);
    } 

    std::sort(v.begin(), v.end());
    int q;
    std::cin >> q;
    for(int i = 0; i < q; i++)
    {
        int qi;
        std::cin >> qi;
        int ans = std::upper_bound(v.begin(), v.end(), qi) - v.begin();
        std::cout << ans << std::endl;
    }
    return 0;
}
