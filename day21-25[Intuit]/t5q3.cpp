#include <bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string &str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << missingNumber(str) << endl;
    }
    return 0;
}

long long cvt(string s)
{
    long long num = 0;
    for (char c : s)
    {
        num = num * 10 + (c - '0');
    }
    // cout<<"num "<<num<<endl;
    return num;
}
int missingNumber(const string &str)
{
    int n = str.size();
    for (int len = 1; len <= 6; len++)
    {
        string temp = "";
        int i = 0, l = len;
        while (i < str.size() && l--)
            temp += str[i++];
        long long prev = cvt(temp), count = 0, j = i, miss, flag = 0;
        temp = "";
        while (j < str.size())
        {
            temp += str[j++];
            if (prev + 1 == cvt(temp))
            {
                prev = cvt(temp);
                temp = "";
            }
            else if (prev + 2 == cvt(temp))
            {
                // cout<<prev<<endl;
                count++;
                miss = prev + 1;
                prev = cvt(temp);
                temp = "";
            }
            else if (prev < cvt(temp))
            {
                flag = 1;
            }
        }

        if (count == 1 && flag == 0)
            return miss;
        // cout<<"!";
    }
    return -1;
}