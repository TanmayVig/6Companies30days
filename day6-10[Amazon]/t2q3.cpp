#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        priority_queue<pair<int, int>> heap;
        vector<int> v;
        for (int i = 0; i < k; i++)
        {
            if (heap.size() < k)
                heap.push({arr[i], i});
        }
        v.push_back(heap.top().first);
        int st = 1, end = k;
        for (; end < n; st++, end++)
        {
            while (!heap.empty() && heap.top().second < st)
            {
                // cout<<heap.top().first<<": "<<heap.top().second<<endl;
                heap.pop();
            }
            heap.push({arr[end], end});
            v.push_back(heap.top().first);
        }
        return v;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}