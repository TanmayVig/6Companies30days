#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> t(n);
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--)
                count++;
            t[i] = count;
        }
        int swp = 0;

        for (int i = 0; i < n; i++)
        {
            int des = n - 1 - i;
            int j = i;
            while (j < n && t[j] < des)
                j++;

            if (j == n)
                return -1;

            swp += (j - i);

            // cout<<j-i<<endl;

            while (j > i)
            {
                t[j] = t[j - 1];
                j--;
            }
        }
        return swp;
    }
};

int main()
{
    Solution obj;
    vector<int> v = {{0, 1, 1, 0},
                     {0, 1, 1, 0},
                     {0, 1, 1, 0},
                     {0, 1, 1, 0}};

    cout << obj.minSwaps(v) << endl;
    return 0;
}