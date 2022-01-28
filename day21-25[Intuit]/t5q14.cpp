#include <bits/stdc++.h>

usign namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    q.push({i, j});
        }

        if (q.size() == 0 || q.size() == n * n)
            return -1;
        int steps = 0;
        while (!q.empty())
        {
            ++steps;
            int size = q.size();
            for (int t = 0; t < size; t++)
            {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                if (i > 0 && i < n && grid[i - 1][j] == 0)
                {
                    q.push({i - 1, j});
                    grid[i - 1][j] = steps;
                }
                if (i >= 0 && i < n - 1 && grid[i + 1][j] == 0)
                {
                    q.push({i + 1, j});
                    grid[i + 1][j] = steps;
                }
                if (j > 0 && j < n && grid[i][j - 1] == 0)
                {
                    q.push({i, j - 1});
                    grid[i][j - 1] = steps;
                }
                if (j >= 0 && j < n - 1 && grid[i][j + 1] == 0)
                {
                    q.push({i, j + 1});
                    grid[i][j + 1] = steps;
                }
            }
        }
        return (steps == 1) ? -1 : steps - 1;
    }
};

int main()
{

    Solution obj;
    vector<vector<int>> g = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    cout << obj.maxDistance(g);
    return 0;
}