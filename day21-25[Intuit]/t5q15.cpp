#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hours(int m, vector<int> piles)
    {
        int h = 0;
        for (int i : piles)
        {
            if (i <= m)
                h++;
            else
            {
                h += ceil((1.0 * i) / m);
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = 1e9;

        // int m;
        while (l <= r)
        {
            int k = (l + r) / 2,
                H = hours((l + r) / 2, piles);
            if (H <= h)
            {
                r = (l + r) / 2 - 1;
            }
            else
            {
                l = (l + r) / 2 + 1;
            }
        }
        return l;
    }
};

int main()
{

    Solution obj;

    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int h = 9;

    cout << obj.minEatingSpeed(v, h) << endl;

    return 0;
}