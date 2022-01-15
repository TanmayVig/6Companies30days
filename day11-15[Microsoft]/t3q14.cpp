#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(int D)
    {
        int i = 1, sum = 0;
        if (D == 0)
            return 0;
        while (sum < D)
            sum += i++;
        if (sum == D)
            return i - 1;
        while ((sum - D) % 2 != 0)
        {
            sum += i++;
        }
        return i - 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int D;
        cin >> D;

        Solution ob;
        cout << ob.minSteps(D) << "\n";
    }
    return 0;
}