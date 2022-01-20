#include <bits/stdc++.h>
using namespace std;

vector<int> split(string s)
{
    int i = 0;
    int num = 0;
    vector<int> v;
    for (; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            v.push_back(num);
            num = 0;
        }
        else
        {
            num = num * 10 + (s[i] - '0');
        }
    }
    v.push_back(num);
    return v;
}

int main()
{
    string x = "10.1.1.3", y = "10.1.1.9";
    vector<int> xv = split(x), yv = split(y);
    if (xv.size() != yv.size())
        x = ((xv.size() > yv.size()) ? x : y);
    else
    {
        int i = 0;
        while (i < xv.size())
        {
            if (xv[i] != yv[i])
            {
                x = ((xv[i] > yv[i]) ? x : y);
                break;
            }
            i++;
        }
    }
    cout << x;
    return 0;
}