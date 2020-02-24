// Leetcode: https://leetcode.com/problems/connecting-cities-with-minimum-cost/
//
// Andy Tseng

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int find_component(int, vector<int>&);
bool unionify(vector<int>&, int, int);

struct edge
{
    int from;
    int to;
    int w;
    edge(int f, int t, int _w) : from(f), to(t), w(_w) {}
};

int min_cost(int n, vector<edge>& connections)
{
    if (connections.size() < n - 1)
    {
        return -1;
    }
    int res = 0, count = 0;
    sort(connections.begin(), connections.end(), [](edge a, edge b){ return a.w < b.w; });
    vector<int> parent(n + 1, 0);
    for (int i = 0; i < parent.size(); ++i) parent[i] = i;

    for (edge e : connections)
    {
        if(unionify(parent, e.from, e.to))
        {
            res += e.w; 
        }
    }

    int comp_num = -1;
    for (int ri = 1; ri < n + 1; ri++)
    {
        int root_num = parent[ri];
        if (comp_num == -1) comp_num = root_num;
        if (comp_num != root_num) return -1;
    }
    return res;
    
}

int find_component(int node, vector<int>& parent)
{
    while (parent[node] != node)
    {
        node = parent[node];
    }  
    return node;
}

bool unionify(vector<int>& parent, int u, int v)
{
    u = find_component(u, parent);
    v = find_component(v, parent);
    if(u == v)
    {
        return false;
    }
    parent[u] = v;
    return true;
}


int main()
{
    vector<edge> edge_list;
    edge_list.push_back({1,2,5});
    edge_list.push_back({1,3,6});
    edge_list.push_back({2,3,1});
    std::cout << min_cost(3, edge_list) << std::endl;

    edge_list.clear();
    edge_list.push_back({1,2,3});
    edge_list.push_back({3,4,4});
    std::cout << min_cost(4,edge_list) << std::endl;

    edge_list.clear();
    edge_list.push_back({1,2,1});
    edge_list.push_back({2,5,1});
    edge_list.push_back({2,4,1});
    edge_list.push_back({1,5,1});
    std::cout << min_cost(5,edge_list) << std::endl;

    return 0;
}
