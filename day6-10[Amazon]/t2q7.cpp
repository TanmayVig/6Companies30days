#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        //  set<char> inq;
        int hash[26] = {0};
        queue<char> q;
        hash[A[0] - 'a']++;
        q.push(A[0]);
        //  inq.insert(A[0]);
        for (int i = 1; i < A.size(); i++)
        {
            //  cout<<A[i];
            hash[A[i] - 'a']++;
            if (hash[A[i] - 'a'] == 1)
                q.push(A[i]);
            if (!q.empty() && A[i] != q.front())
            {
                A[i] = q.front();
            }
            else
            {
                //  hash[A[i]-'a']++;
                while (!q.empty() && hash[q.front() - 'a'] > 1)
                    q.pop();
                if (q.empty())
                    A[i] = '#';
                else
                    A[i] = q.front();
            }
        }
        return A;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}