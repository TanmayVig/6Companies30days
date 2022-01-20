#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int filter_opr(vector<int> a)
    {
        int n = a.size();
        vector<int> sub_b;
        for (int i = 0; i < n; i++)
        {
            auto lb = lower_bound(sub_b.begin(), sub_b.end(), a[i]);
            if (lb == sub_b.end())
            {
                sub_b.push_back(a[i]);
            }
            else
            {
                *lb = min(*lb, a[i]);
            }
        }
        return sub_b.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M)
    {
        unordered_set<int> st;
        for (int i = 0; i < M; i++)
        {
            st.insert(B[i]);
        }
        vector<int> a_;
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (st.find(A[i]) != st.end())
            {
                a_.push_back(A[i]);
            }
            else
                count++;
        }
        int len = a_.size();
        return count + len - filter_opr(a_) + M - filter_opr(a_);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        int A[N], B[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.minInsAndDel(A, B, N, M) << endl;
    }
    return 0;
}