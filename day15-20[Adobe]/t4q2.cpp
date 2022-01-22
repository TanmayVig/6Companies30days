#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestAP(int A[], int n)
    {
        int d_max = A[n - 1] - A[0];
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[A[i]] = i;
        }
        vector<int> t(d_max + 1, 1);
        vector<vector<int>> dp(n, t);
        int l = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= d_max; j++)
            {
                if (m.count(A[i] - j) == 1)
                {
                    // cout<<((A[i]-j))<<endl;
                    dp[i][j] = dp[i][j] + dp[m[A[i] - j]][j];
                    l = max(l, dp[i][j]);
                }
            }
        }

        return l;
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}