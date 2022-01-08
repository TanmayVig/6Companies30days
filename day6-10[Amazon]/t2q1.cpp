#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[501][2][201];

public:
    int maxProfit(int K, int N, int A[])
    {
        for (int i = N - 1; i >= 0; i--)
        {
            for (int tr = 0; tr <= K; tr++)
            {
                if (i == N - 1)
                {
                    dp[i][0][tr] = 0;
                    dp[i][1][tr] = (tr >= 1) ? A[i] : 0;
                }
                else
                {
                    dp[i][1][tr] = max(dp[i + 1][1][tr], (tr >= 1) ? A[i] + dp[i + 1][0][tr - 1] : 0);
                    dp[i][0][tr] = max(dp[i + 1][0][tr], -A[i] + dp[i + 1][1][tr]);
                }
            }
        }
        return dp[0][0][K];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}