#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(vector<int> &v, int trg, int i)
    {
        if (i == v.size())
            return trg == 0;
        int n = v[i];
        if (dfs(v, trg, i + 1))
            return true;
        v[i] = -n;
        if (dfs(v, trg - n, i + 1))
            return true;
        v[i] = n;
        return false;
    }

    vector<int> recoverArray(int n, vector<int> &sums)
    {
        int mn = *min_element(sums.begin(), sums.end());
        for (int &i : sums)
            i -= mn;
        vector<int> ans;
        multiset<int> s(sums.begin(), sums.end()), temp;
        for (int i = 0; i < n; i++)
        {
            int t = *next(s.begin());
            ans.push_back(t);
            while (s.size())
            {
                int f = *s.begin();
                temp.insert(f);
                s.erase(s.begin());
                s.erase(s.find(f + t));
            }
            swap(temp, s);
        }
        dfs(ans, -mn, 0);
        return ans;
    }
};

int main()
{
    Solution obj;
    int n = 3;
    vector<int> sums = {-3, -2, -1, 0, 0, 1, 2, 3};
    cout << obj.recoverArray(n, sums) << endl;
    return 0;
}