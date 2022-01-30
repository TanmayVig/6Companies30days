#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int height(int N)
    {
        return (-1 + pow(1 + 4 * 2 * N, 0.5)) / 2;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.height(N) << endl;
    }
    return 0;
}