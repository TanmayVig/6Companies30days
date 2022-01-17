#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        long long sum_rng = 0;
        for (int i = 0; i < N; i++)
        {
            sum_rng += arr[i];
        }
        if (sum_rng % 2 == 1)
            return 0;
        bool dp[N + 1][sum_rng + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= sum_rng; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        for (int i = 0; i <= sum_rng; i++)
        {
            if (dp[N][i] == true && (sum_rng == 2 * i))
                return 1;
        }
        return 0;
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}