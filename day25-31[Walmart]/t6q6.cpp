
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

class Solution
{
public:
    // You need to complete this fucntion

    long long power(long long x, int y)
    {
        // static int mod = 1e9+7;
        long long result = 1;
        while (y > 0)
        {
            if (y % 2 == 0)
            {
                x = (x % mod * x % mod) % mod;
                y = y / 2;
            }
            else
            {
                result = (result % mod * x % mod) % mod;
                y--;
            }
        }
        return result;
    }
};

// compute reverse of a number
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

int main()
{
    int T;
    cin >> T; // testcases

    while (T--)
    {
        long long N;
        cin >> N; // input N

        long long R = 0;

        // reverse the given number n
        R = rev(N);
        Solution ob;
        // power of the number to it's reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
}