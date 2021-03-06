#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void topo_sort(int src, vector<int> &visited, vector<int> &topo, vector<int> adj[])
    {
        visited[src] = 1;
        for (auto i : adj[src])
        {
            if (!visited[i])
                topo_sort(i, visited, topo, adj);
        }
        topo.push_back(src);
    }

    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < min(dict[i].size(), dict[i + 1].size()); j++)
            {
                if (dict[i][j] != dict[i + 1][j])
                {
                    adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                    break;
                }
            }
        }

        vector<int> visited(K, 0);
        vector<int> topo;

        for (int i = 0; i < K; i++)
        {
            if (!visited[i])
            {
                topo_sort(i, visited, topo, adj);
            }
        }
        string s = "";
        reverse(topo.begin(), topo.end());
        for (int i = 0; i < topo.size(); i++)
        {
            s += topo[i] + 'a';
        }
        return s;
    }
};

string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}