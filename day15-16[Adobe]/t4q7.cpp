#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans(vector<vector<int>> &dp, vector<int> A, int i, int j, int n)
    {
        if (i > j || i >= n)
            return 0;
        if (dp[i][j] != 0)
            return dp[i][j];
        if (i == j)
        {
            dp[i][j] = A[i];
        }
        else if (i < j)
        {
            dp[i][j] = max(A[i] + min(ans(dp, A, i + 2, j, n), ans(dp, A, i + 1, j - 1, n)), A[j] + min(ans(dp, A, i + 1, j - 1, n), ans(dp, A, i, j - 2, n)));
        }
        return dp[i][j];
    }
    int maxCoins(vector<int> &A, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        ans(dp, A, 0, n - 1, n);
        return dp[0][n - 1];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}