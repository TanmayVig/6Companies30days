#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int divid, int divis)
    {
        if (divid == INT_MIN && divis == -1)
            return INT_MAX;
        int sign = (divid > 0 ^ divis > 0) ? -1 : 1;
        long a = labs(divid), b = labs(divis);
        cout << sign << " " << a << " " << b << endl;
        long count = 0;
        while (a >= b)
        {
            long t = b, m = 1;
            while (t << 1 <= a)
            {
                t <<= 1;
                m <<= 1;
            }
            a -= t;
            count += m;
        }
        cout << count << endl;
        if (sign * count > INT_MAX)
            return INT_MAX;
        if (sign * count < INT_MIN)
            return INT_MIN;
        return sign * count;
    }
};

int main()
{
    Solution obj;
    cout << obj.divide(2, 3) << endl;
    return 0;
}