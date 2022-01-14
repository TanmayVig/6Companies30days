#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        int leftmax = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (price[i] >= price[leftmax])
            {
                ans[i] = i + 1;
                leftmax = i;
            }
            else
            {
                int count = 0;
                for (int j = i; j >= leftmax; j--)
                {
                    if (price[i] < price[j])
                        break;
                    count++;
                }
                ans[i] = count;
            }
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
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}