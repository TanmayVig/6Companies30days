#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    map<int, set<int>> m;

    set<int> dfs(vector<int> adj[], int v, int c)
    {
        stack<int> st;
        st.push(c);
        // st.push()
        set<int> visited;
        while (!st.empty())
        {
            int t = st.top();
            st.pop();
            if (t < 0)
                continue;
            visited.insert(t);

            for (int i = 0; i < adj[t].size(); i++)
            {
                if (visited.find(adj[t][i]) == visited.end())
                    st.push(adj[t][i]);
            }
        }
        return visited;
    }

    int isBridge(int V, vector<int> adj[], int c, int d)
    {

        set<int> bef = dfs(adj, V, c);
        // for(int i : bef) cout<<i<<" ";
        // cout<<endl;

        // adj[c][d]=adj[d][c]=0;
        for (int i = 0; i < adj[c].size(); i++)
        {
            if (adj[c][i] == d)
            {
                adj[c][i] = -1;
            }
        }
        for (int i = 0; i < adj[d].size(); i++)
        {
            if (adj[d][i] == c)
            {
                adj[d][i] = -1;
            }
        }

        set<int> aft = dfs(adj, V, c);
        // for(int i: aft) cout<<i<<" ";
        // cout<<endl;
        return (aft == bef) ? 0 : 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}
