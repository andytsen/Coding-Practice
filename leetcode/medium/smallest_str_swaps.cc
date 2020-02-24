#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int find(int n, vector<int>& grouping)
{
    while (grouping[n] != n)
    {
        n = grouping[n];
    }
    return grouping[n];
}

void union_find(int a, int b, vector<int>& grouping)
{
    int a_grp = find(a,grouping); 
    int b_grp = find(b,grouping);
    if (a_grp == b_grp)
    {
        return;
    }
    grouping[a] = a_grp;
    for(int i = 0; i < grouping.size(); ++i)
    {
        if (grouping[i] == b_grp)
        {
            grouping[i] = a_grp;
        }
    }
}

string smallest_str_swaps(string s, vector<pair<int,int>>& pairings)
{
    vector<int> grouping(s.size(), 0); 
    for(int i = 0; i < s.size(); ++i) grouping[i] = i;
     
    for(pair<int,int> p : pairings)
    {
        union_find(p.first, p.second, grouping);
    }

    map<int, vector<int>> index_grouping_map;
    for(int i = 0; i < grouping.size(); ++i)
    {
        int grp = grouping[i];
        if (index_grouping_map.find(grp) == index_grouping_map.end())
        {
            index_grouping_map[grp] = vector<int>();
        }
        index_grouping_map[grp].push_back(i);
    }


    for (auto it = index_grouping_map.begin(); it != index_grouping_map.end(); ++it)
    {
        vector<int>& indexes = it->second;
        vector<char> combined_char_group;
        for (int index : indexes)
        {
            combined_char_group.push_back(s[index]);
        }
        sort(combined_char_group.begin(), combined_char_group.end()); 
        for(int i = 0; i < indexes.size(); ++i)
        {
            s[indexes[i]] = combined_char_group[i];
        }
    }
    return s;
}


int main()
{
    vector<pair<int,int>> swap_pairs = { {0,3}, {1,2}, {0,2} };
    std::cout << smallest_str_swaps("dcab", swap_pairs) << std::endl;
    swap_pairs = { {0,3}, {1,2} };
    std::cout << smallest_str_swaps("dcab", swap_pairs) << std::endl;
    return 0;
}

