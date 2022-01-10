#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<string, pair<int, string>> dp;
    pair<int, string> tool(int p[], int l, int r)
    {
        if (l + 1 == r)
            return {0, "" + string(1, l + 'A')};
        string k = to_string(l) + "," + to_string(r);
        if (dp.count(k))
            return dp[k];
        int mini = INT_MAX;
        string minis = "";
        for (int i = l + 1; i < r; i++)
        {
            pair<int, string> p1 = tool(p, l, i), p2 = tool(p, i, r);
            if (p1.first + p2.first + p[l] * p[i] * p[r] < mini)
            {
                mini = p1.first + p2.first + p[l] * p[i] * p[r];
                minis = "(" + p1.second + p2.second + ")";
            }
        }
        return dp[k] = {mini, minis};
    }
    string matrixChainOrder(int p[], int n)
    {
        return tool(p, 0, n - 1).second;
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
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
}