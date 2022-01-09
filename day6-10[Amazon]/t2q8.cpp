#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countWays(int m)
    {
        return ((long long)m) / 2 + 1;
    }
};

int main()
{
    // taking count of testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}