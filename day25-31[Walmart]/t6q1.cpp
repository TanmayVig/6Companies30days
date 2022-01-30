#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        priority_queue<pair<double, int>> q;
        vector<double> vis(n, 0);
        vis[start] = 1;
        for (auto p : graph[start])
        {
            q.push({p.first, p.second});
            cout << "node: " << p.second << " prob: " << p.first << endl;
        }
        while (!q.empty())
        {
            auto top = q.top();
            q.pop();
            int node = top.second;
            double prob = top.first;

            // cout<<"node: "<<node<<" prob: "<<prob<<" vis[node]: "<<vis[node]<<endl;
            if (vis[node] >= prob)
                continue;

            vis[node] = prob;

            for (auto p : graph[node])
            {
                q.push({prob * p.first, p.second});
            }
        }
        return vis[end];
    }
};

int main()
{
    Solution obj;
    int n = 3, start = 0, end = 2;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    return 0;
}