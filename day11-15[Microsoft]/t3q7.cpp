#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find unit area of the largest region of 1s.
    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        int count = 0;
        stack<pair<int, int>> st;
        st.push({r, c});
        while (!st.empty())
        {
            pair<int, int> t = st.top();
            st.pop();
            if (grid[t.first][t.second] == -1)
                continue;
            grid[t.first][t.second] *= -1;
            count++;
            int i = t.first, j = t.second;
            // cout<<i<<","<<j<<endl;
            if (i - 1 >= 0 && grid[i - 1][j] == 1)
                st.push({i - 1, j});
            if (i + 1 < (grid.size()) && grid[i + 1][j] == 1)
                st.push({i + 1, j});
            if (j - 1 >= 0 && grid[i][j - 1] == 1)
                st.push({i, j - 1});
            if (j + 1 < grid[i].size() && grid[i][j + 1] == 1)
                st.push({i, j + 1});
            if (i - 1 >= 0)
            {
                if (j - 1 >= 0 && grid[i - 1][j - 1] == 1)
                    st.push({i - 1, j - 1});
                if (j + 1 < grid[i].size() && grid[i - 1][j + 1] == 1)
                    st.push({i - 1, j + 1});
            }
            if (i + 1 < grid.size())
            {
                if (j - 1 >= 0 && grid[i + 1][j - 1] == 1)
                    st.push({i + 1, j - 1});
                if (j + 1 < grid[i].size() && grid[i + 1][j + 1] == 1)
                    st.push({i + 1, j + 1});
            }
        }
        return count;
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        int count = 0;
        int m = grid[0].size(), n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    count = max(count, dfs(grid, i, j));
                }
            }
        }
        return count;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}