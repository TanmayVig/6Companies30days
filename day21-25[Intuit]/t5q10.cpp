#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, int i, unordered_set<int> &s)
    {
        stack<int> st;
        st.push(i);
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (s.find(top) != s.end())
                continue;
            s.insert(top);

            s.insert(top);
            for (int j = 0; j < isConnected[top].size(); j++)
            {
                if (isConnected[top][j] == 1 && s.find(j) == s.end())
                    st.push(j);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        unordered_set<int> s;
        int n = isConnected.size(), m = isConnected[0].size(), count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.find(i) == s.end())
            {
                dfs(isConnected, i, s);
                count++;
            }
        }
        return count;
    }
};

int main()
{

    vector<int> v = {{1, 1, 0},
                     {1, 1, 0},
                     {0, 0, 1}};
    Solution obj;
    cout << obj.findCircleNum(v);
    return 0;
}