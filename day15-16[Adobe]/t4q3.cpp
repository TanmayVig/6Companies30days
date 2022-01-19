#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int M = 1e9 + 7;
    int kvowelwords(int N, int K)
    {
        vector<vector<long long int>> dp(N + 1, vector<long long int>(K + 1, 1));
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= K; j++)
            {
                dp[i][j] = (dp[i - 1][K] * 21) % M;
                if (j > 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * 5 % M) % M;
                }
            }
        }
        return dp[N][K];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        int K;
        cin >> N >> K;

        Solution ob;
        int ans = ob.kvowelwords(N, K);
        cout << ans << endl;
    }
    return 0;
}