#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        // set<array<int,3>> s;
        int res = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<long, int> dist(points.size());

            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                int dx = points[i][0] - points[j][0],
                    dy = points[i][1] - points[j][1];

                int key = dx * dx;
                key += dy * dy;
                ++dist[key];
            }

            for (pair<long, int> p : dist)
            {
                if (p.second > 1)
                    res += p.second * (p.second - 1);
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> p = {{0, 0}, {1, 0}, {2, 0}};
    Solution obj;
    cout << obj.numberOfBoomerangs << endl;
    return 0;
}