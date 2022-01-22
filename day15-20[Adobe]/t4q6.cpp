#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

class Solution
{
public:
    void paran(vector<string> &v, string s, int o, int c)
    {
        if (o == 0 && c == 0)
        {
            v.push_back(s);
        }

        if (o != 0)
            paran(v, s + '(', o - 1, c);
        if (o < c)
            paran(v, s + ')', o, c - 1);
    }
    vector<string> AllParenthesis(int n)
    {
        vector<string> v;
        paran(v, "", n, n);
        return v;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}