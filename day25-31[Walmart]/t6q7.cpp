#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (v1[n - 1] == v2[m - 1])
        return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

class Solution
{
public:
    vector<int> find3Numbers(vector<int> a, int N)
    {
        stack<int> st;
        for (int i = N - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= a[i])
            {
                // cout<<st.top()<<endl;
                st.pop();
            }
            st.push(a[i]);

            if (st.size() == 3)
                break;
        }
        vector<int> v;
        while (!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        if (v.size() == 3)
            return v;
        return {};
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3)
        {
            cout << -1 << "\n";
        }

        if (res.empty())
        {
            cout << 0 << "\n";
        }
        else if ((res[0] < res[1] and res[1] < res[2]) and
                 isSubSequence(a, res, n, res.size()))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}