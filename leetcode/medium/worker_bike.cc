// bike to worker
// each bike to worker pair has a distance


int assign_bikes(vector<pair<int,int>>& bikes, vector<pair<int,int>>& workers)
{
    int m = bikes.size();
    int n = workers.size();
    vector<vector<int>> dists = vector<vector<int>>(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            dists[i][j] = bikes[i]
        }
    }
}


