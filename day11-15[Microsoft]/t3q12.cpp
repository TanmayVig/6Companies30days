// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        map<int, set<int>> loc;
        vector<vector<int>> ans;
        int len = arr.size();
        for (int i = 0; i < len - 3; i++)
        {
            for (int j = i + 1; j < len - 2; j++)
            {
                int l = j + 1, r = len - 1;
                while (l < r)
                {
                    if (arr[l] + arr[r] + arr[i] + arr[j] < k)
                    {
                        l++;
                    }
                    else if (arr[l] + arr[r] + arr[i] + arr[j] > k)
                    {
                        r--;
                    }
                    else
                    {
                        vector<int> v(4, 0);
                        v[0] = arr[i];
                        v[1] = arr[j];
                        v[2] = arr[l];
                        v[3] = arr[r];
                        ans.push_back(v);
                        while (l < r && arr[l] == v[2])
                            l++;
                        while (l < r && arr[r] == v[3])
                            r--;
                    }
                }
                while (j + 1 < len && arr[j + 1] == arr[j])
                    j++;
            }
            while (i + 1 < len && arr[i + 1] == arr[i])
                i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends