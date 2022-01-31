#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> e_s;
        for (int i = 0; i < speed.size(); i++)
        {
            e_s.push_back({efficiency[i], speed[i]});
        }
        sort(e_s.rbegin(), e_s.rend());
        long sp_sum = 0, res = 0;

        priority_queue<int, vector<int>, greater<int>> q;

        for (auto [e, s] : e_s)
        {
            q.push(s);
            sp_sum += s;
            if (q.size() > k)
            {
                sp_sum -= q.top();
                q.pop();
            }
            res = max(res, sp_sum * e);
        }
        return res % (int)(1e9 + 7);
    }
};

int main()
{
    Solution obj;
    int n = 6, k = 2;
    vector<int> speed = [ 2, 10, 3, 1, 5, 8 ], efficiency = [ 5, 4, 3, 9, 7, 2 ];
    cout << obj.maxPerformance(n, speed, efficiency, k) << endl;
    return 0;
}