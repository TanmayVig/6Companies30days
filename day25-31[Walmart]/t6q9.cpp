#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int util(vector<vector<int>> &dp, int s, int e)
    {
        if (s >= e)
            return 0;
        if (dp[s][e] != 0)
            return dp[s][e];
        int res = INT_MAX;
        for (int i = s; i <= e; i++)
        {
            int temp = i + max(util(dp, s, i - 1), util(dp, i + 1, e));
            res = min(res, temp);
        }
        return dp[s][e] = res;
    }
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return util(dp, 1, n);
    }
};

int main()
{
    Solution obj;
    cout << obj.getMoneyAmount(10) << endl;
    return 0;
}