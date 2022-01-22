#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        int range_sum = 0;
        for (int i = 0; i < n; i++)
        {
            range_sum += arr[i];
        }
        bool dp[n + 1][range_sum + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j <= range_sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int mn = range_sum;
        for (int i = 0; i <= range_sum / 2; i++)
            if (dp[n][i] == true)
                mn = min(mn, abs(range_sum - 2 * i));
        return mn;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}