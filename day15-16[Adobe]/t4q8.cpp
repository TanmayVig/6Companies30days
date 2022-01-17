#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        int num = 0;
        int sign = 1;
        if (str[0] == '-')
        {
            sign = -1;
            str = str.substr(1);
        }
        for (char c : str)
        {
            if (!(c >= '0' && c <= '9'))
                return -1;
            num = num * 10 + (c - '0');
        }
        return sign * num;
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
        cout << ob.atoi(s) << endl;
    }
}