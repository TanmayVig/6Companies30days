#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());

        for (auto pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
            // cout<<"run graph loop"<<endl;
        }
        queue<int> que;
        for (int i = 0; i < indegree.size(); i++)
            if (indegree[i] == 0)
                que.push(i);

        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            res.push_back(u);
            for (auto v : graph[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    que.push(v);
            }
        }
        if (res.size() == numCourses)
            return res;
        else
            return vector<int>();
    }
};

int main()
{

    Solution obj;
    vector<int> g = {};
    cout << obj.findOrder(2, g) << endl;
    return 0;
}