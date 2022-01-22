#include <bits/stdc++.h>
using namespace std;
#define N 1000

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSA[][N], int n, int k)
    {
        multiset<pair<int, pair<int, int>>, less<pair<int, pair<int, int>>>> h;
        int max_ = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            h.insert({KSA[i][0], {i, 0}});
            max_ = max(max_, KSA[i][0]);
        }
        pair<int, int> min_pair;
        pair<int, pair<int, int>> p = *h.begin();
        min_pair = {p.first, max_};
        int min_range = max_ - p.first;

        while (true)
        {
            auto it = h.begin();

            if (min_range > max_ - (*it).first)
            {
                min_range = max_ - (*it).first;
                min_pair = {(*it).first, max_};
            }

            if ((*it).second.second == n - 1)
                break;
            // h.erase(it);
            int e = KSA[(*it).second.first][(*it).second.second + 1];
            max_ = max(max_, e);
            h.insert({e, {(*it).second.first, (*it).second.second + 1}});
            h.erase(it);
        }
        return min_pair;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}
