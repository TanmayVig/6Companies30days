#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, vector<int>> graph;
    bool isCycle(int v, bool visited[], bool *recstack)
    {
        if (visited[v] == false)
        {
            visited[v] = true;
            recstack[v] = true;

            for (int i : graph[v])
            {
                if (!visited[i] && isCycle(i, visited, recstack) || recstack[i])
                    return true;
            }
        }
        recstack[v] = false;
        return false;
    }
    bool isPossible(int N, vector<pair<int, int>> &p)
    {

        // stack<int> st;
        for (int i = 0; i < p.size(); i++)
        {
            graph[p[i].first].push_back(p[i].second);
            // st.push(p[i].second);
        }

        bool visited[N] = {false}, recstack[N] = {false};

        for (int i = 0; i < N; i++)
        {
            if (isCycle(i, visited, recstack))
                return false;
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}