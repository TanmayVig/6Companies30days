#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string colName(long long int n)
    {
        string ans = "";
        while (n != 0)
        {
            n--;
            int r = n % 26;
            // cout<<r<<" "<<(char)(r+'A')<<" "<<n<<endl;
            ans = (char)(r + 'A') + ans;
            n /= 26;
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
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.colName(n) << '\n';
    }
}