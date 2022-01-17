#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        unordered_map<string, int> m;
        int max_ = 0;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
            max_ = max(max_, m[arr[i]]);
        };
        set<string> s;
        for (pair<string, int> p : m)
        {
            if (p.second == max_)
                s.insert(p.first);
        }
        return {*s.begin(), to_string(max_)};
    }
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        string arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);

        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}