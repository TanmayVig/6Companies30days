#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int sum1 = max(arr[0], arr[1]), sum2 = arr[0], curr_sum = 0;
        if (n == 1)
            return arr[0];
        if (n == 2)
            return max(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            curr_sum = max(arr[i] + sum2, sum1);
            sum2 = sum1;
            sum1 = curr_sum;
        }
        return curr_sum;
    }
};

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}