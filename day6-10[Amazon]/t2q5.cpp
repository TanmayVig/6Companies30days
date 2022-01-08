// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> v;
        vector<string> temp;
        set<string> st;
        for (int i = 0; i < n; i++)
        {
            if (contact[i][0] == s[0])
            {
                // temp.push_back(contact[i]);
                st.insert(contact[i]);
            }
        }

        if (!st.empty())
        {
            for (auto i : st)
            {
                temp.push_back(i);
            }
            v.push_back(temp);
        }
        else
        {
            temp.push_back("0");
            for (int i = 0; i < s.size(); i++)
            {
                v.push_back(temp);
            }
            return v;
        }

        for (int i = 1; i < s.size(); i++)
        {
            temp.clear();
            string str = s.substr(0, i + 1);
            for (int j = 0; j < v[i - 1].size(); j++)
            {
                if (v[i - 1][j].substr(0, i + 1) == str)
                {
                    temp.push_back(v[i - 1][j]);
                }
            }
            if (temp.size() == 0)
            {
                temp.push_back("0");
                while (i < s.size())
                {
                    v.push_back(temp);
                    i++;
                }
                return v;
            }
            else
                v.push_back(temp);
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends