
#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>

using namespace std;

struct edge
{
    int from;
    int to;
    int weight;   
};

// len of shortest path from src to dest
int bfs(int src, int dest, vector<vector<int>>& graph)
{
    queue<int> nodes;
    nodes.push(src);
    int len = 0; int lvl_amnt = 1;
    //use bfs?
    while(!nodes.empty())
    {
        int tmp_amnt = 0;
        for(int i = 0; i < lvl_amnt; ++i) {
            int top = nodes.front();
            if (top == dest)
            {
                return len;
            }
            nodes.pop();
            for(int j = 0; j < graph[top].size(); ++j)
            {
                if (graph[top][j] > 0)
                {
                    nodes.push(j);
                    tmp_amnt++;
                }
            }
        }
        len++;
        lvl_amnt = tmp_amnt;
    }
    return -1; // never found?
}

int weighted_djikstra(int src, int dest, vector<vector<int>>& graph)
{
    vector<int> d(graph.size(), INT_MAX);
    priority_queue<std::pair<int,int>> pq;
    pq.push(std::pair<int,int>(0,src));

    while (!pq.empty())
    {
        std::pair<int,int> top = pq.top(); 
        int cur = top.second;
        int cost = top.first;
        pq.pop();
        for(int i = 0; i < graph[cur].size(); ++i)
        {
            if (graph[cur][i] > 0)
            {
                if (cost + graph[cur][i] < d[i])
                {
                    d[i] = cost + graph[cur][i];
                }
                pq.push(std::pair<int,int>(cost + graph[cur][i],i));
            }
        }
    }

    return d[dest];
}



int main()
{
    vector<vector<int>> graph(3, vector<int>(3, 0));
    graph[0][1] = 1; 
    graph[1][2] = 1; 
    std::cout << bfs(0,1,graph) << std::endl;
    std::cout << bfs(0,2,graph) << std::endl;

    std::cout << "======= Weighted Djikstra test now ======= " << std::endl;

    vector<vector<int>> graph2(7, vector<int>(3,0)); 
    graph2[0][1] = 2;
    graph2[1][2] = 4;
    std::cout << weighted_djikstra(0,1,graph2) << std::endl;
    std::cout << weighted_djikstra(1,2,graph2) << std::endl;
}
