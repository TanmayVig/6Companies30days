#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the largest number after k swaps.
    string max = "0";
    void util(string str, string &max, int k, int pos)
    {
        if (k == 0)
            return;

        char c = str[pos];
        for (int i = pos + 1; i < str.length(); i++)
        {
            if (c < str[i])
            {
                c = str[i];
            }
        }
        if (c != str[pos])
            k--;
        for (int i = str.length() - 1; i >= pos; i--)
        {
            if (str[i] == c)
            {
                swap(str[i], str[pos]);
                if (str.compare(max) > 0)
                {
                    max = str;
                }
                util(str, max, k, pos + 1);
                swap(str[i], str[pos]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        max = str;
        util(str, max, k, 0);
        return max;
    }
};

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
