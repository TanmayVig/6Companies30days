#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        queue<int> q;
        q.push(0);
        long long sum = arr[0];
        int r = 1;
        while (r <= n)
        {
            if (sum == s)
                break;
            else if (sum > s)
            {
                sum -= arr[q.front()];
                q.pop();
            }
            else
            {
                sum += arr[r];
                q.push(r++);
            }
        }
        if (sum == s)
            return {q.front() + 1, r};
        return {-1};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}