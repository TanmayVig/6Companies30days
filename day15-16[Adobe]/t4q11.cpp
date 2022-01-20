#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string amendSentence(string s)
    {

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                ans += s[i];
            else if (i != 0)
                ans = ans + ' ' + (char)(s[i] - 'A' + 'a');
            else
                ans = ans + (char)(s[i] - 'A' + 'a');
        }
        return ans;
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
        Solution ob;
        cout << ob.amendSentence(s) << endl;
    }
}