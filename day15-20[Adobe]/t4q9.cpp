#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string nextPalin(string N)
    {
        int l = N.size();
        string left = N.substr(0, l / 2);
        for (int i = left.size() - 1; i > 0; i--)
        {
            if (left[i] > left[i - 1])
            {
                int min_diff_i = i;
                for (int j = i; j < l / 2; j++)
                {
                    if (left[j] > left[i - 1] && (left[j] <= left[min_diff_i]))
                        min_diff_i = j;
                }
                swap(left[i - 1], left[min_diff_i]);
                reverse(left.begin() + i, left.end());
                break;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (l % 2)
            left = left + N[l / 2];
        if (left + right == N)
            return "-1";
        return left + right;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}