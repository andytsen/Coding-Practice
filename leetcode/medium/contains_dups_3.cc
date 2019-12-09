#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

bool contains_nearby_almost_dups(vector<int>& nums, int k, int t)
{
    bool res = false;
    unordered_map<int, set<int>> num_to_indexes;
    for(int i = 0; i < nums.size(); ++i)
    {
        // search for an nearby-almost-duplicate in the map
        int n = nums[i];
        for(int ti = 0; abs(n - ti) <= t; ++ti)
        {
            if (num_to_indexes.find(ti) != num_to_indexes.end())
            {
                set<int> indexes = num_to_indexes[ti];
                for (int index : indexes)
                {
                    if (abs(i - index) <= k)
                    {
                        res = true;
                    }
                }
            } 
        }
        if (num_to_indexes.find(n) == num_to_indexes.end())
        {
            num_to_indexes[n] = set<int>(); 
        }
        num_to_indexes[n].insert(i);
    }

    // debugging purposes
    auto it = num_to_indexes.begin();
    while ( it != num_to_indexes.end())
    {
        cout << it->first << " { ";
        set<int> s = it->second;
        for(int si : s)
        {
            cout << si << " ";
        }
        cout << "}" << endl;
        ++it;
    }
    return res;
}

int main()
{
    vector<int> v = {1,2,3,1};
    cout << contains_nearby_almost_dups(v, 3, 0) << endl;
    cout << "----------------------------------\n";
    vector<int> p = {1,0,1,1};
    cout << contains_nearby_almost_dups(p, 1, 2) << endl;
    cout << "----------------------------------\n";
    vector<int> q = {1,5,9,1,5,9};
    cout << contains_nearby_almost_dups(q, 2, 3) << endl;
    cout << "----------------------------------\n";
    return 0;
}
