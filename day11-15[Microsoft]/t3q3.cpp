#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix);

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    // //transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // mirror;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
