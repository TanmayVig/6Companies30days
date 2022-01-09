#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        int row_h[9][9] = {0}, col_h[9][9] = {0}, block[9][9] = {0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (mat[i][j] != 0)
                {
                    row_h[i][mat[i][j] - 1]++;
                    col_h[j][mat[i][j] - 1]++;
                    block[(i / 3) * 3 + j / 3][mat[i][j]]++;
                    if (row_h[i][mat[i][j] - 1] > 1 || col_h[j][mat[i][j] - 1] > 1 || block[(i / 3) * 3 + j / 3][mat[i][j]] > 1)
                        return 0;
                }
            }
        }
        return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
}