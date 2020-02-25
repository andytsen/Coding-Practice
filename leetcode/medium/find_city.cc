#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <unordered_map>
#include <queue>

using namespace std;

struct edge
{
    int from;
    int to;
    int weight;
    edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};


void djikstra(int src, vector<int>& v, vector<vector<int>>& graph, int threshold)
{
    vector<int> d(graph.size(), INT_MAX); 
    priority_queue<std::pair<int,int>> pq; 
    pq.push(std::pair<int,int>(0,src));

    while(!pq.empty())
    {
        std::pair<int,int> top = pq.top();
        int n_cur = top.second;
        int w_cur = top.first;
        pq.pop();
        for(int i = 0; i < graph[n_cur].size(); ++i)
        {
            if (graph[n_cur][i] > 0)
            {
                if (w_cur + graph[n_cur][i] < d[i])
                {
                    pq.push(std::pair<int,int>(w_cur + graph[n_cur][i], i));
                    d[i] = w_cur + graph[n_cur][i];
                }
            }
        }
    }
    for (int di = 0; di < d.size(); ++di)
    {
        if(d[di] <= threshold && di != src)
            v[di]++;
    }

}

int find_city(int num_verts, vector<edge>& edges, int distance_threshold)
{
    vector<vector<int>> graph(num_verts, vector<int>(num_verts, 0));
    for (edge e : edges)
    {
        graph[e.from][e.to] = e.weight;
        graph[e.to][e.from] = e.weight;
    }

    vector<int> neighbors(num_verts,0);
    for(int i = 0; i < num_verts; ++i)
    {
        djikstra(i, neighbors, graph, distance_threshold);
    }
    
    int min_val = INT_MAX;
    int city_num;
    for (int ni = 0; ni < neighbors.size(); ++ni)
    {
        if (neighbors[ni] <= min_val)
        {
            min_val = neighbors[ni];
            city_num = ni;
        }
    }
    return city_num;
}

int main()
{
    vector<edge> e;
    edge e1(0,1,3);
    edge e2(1,2,1);
    edge e3(1,3,4);
    edge e4(2,3,1);
    e.push_back(e1);
    e.push_back(e2);
    e.push_back(e3);
    e.push_back(e4);
    cout << find_city(4, e, 4) << endl;

    e.clear();
    e.push_back({0,1,2});
    e.push_back({0,4,8});
    e.push_back({1,2,3});
    e.push_back({1,4,2});
    e.push_back({2,3,1});
    e.push_back({3,4,1});
    cout << find_city(5, e, 2) << endl;

    e.clear();
    e.push_back({0,3,7});
    e.push_back({2,4,1});
    e.push_back({0,1,5});
    e.push_back({2,3,0});
    e.push_back({1,3,6});
    e.push_back({1,2,1});
    cout << find_city(6, e, 417) << endl;


}
