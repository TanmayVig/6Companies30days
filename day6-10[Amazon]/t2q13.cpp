#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q1;
    const int n = grid.size(), m = grid[0].size();
    pair<int, int> rot1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                rot1 = {i, j};
                q1.push(rot1);
            }
        }
    }
    q1.push(rot1);
    int time = 0;
    while (!q1.empty())
    {
        queue<pair<int, int>> temp;
        cout << time << endl;
        time++;
        while (!q1.empty())
        {
            pair<int, int> top = q1.front();
            int f = top.first, s = top.second;
            if (f != 0 && grid[f - 1][s] == 1)
            {
                grid[f - 1][s] = 2;
                temp.push({f - 1, s});
            }
            if (f != n - 1 && grid[f + 1][s] == 1)
            {
                grid[f + 1][s] = 2;
                temp.push({f + 1, s});
            }
            if (s != 0 && grid[f][s - 1] == 1)
            {
                grid[f][s - 1] = 2;
                temp.push({f, s - 1});
            }
            if (s != m - 1 && grid[f][s + 1] == 1)
            {
                grid[f][s + 1] = 2;
                temp.push({f, s + 1});
            }
            q1.pop();
        }
        q1 = temp;
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j : grid[i])
        {
            if (j == 1)
                return -1;
        }
    }
    return time;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid);
    return 0;
}