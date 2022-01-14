#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
public:
    // Function to find list of all words possible by pressing given numbers.
    void words(int a[], int n, int i, string s, vector<string> &v, map<int, string> m)
    {
        if (i >= n)
        {
            v.push_back(s);
            return;
        }
        string temp = m[a[i]];
        for (int j = 0; j < temp.size(); j++)
        {
            words(a, n, i + 1, s + temp[j], v, m);
        }
        return;
    }

    vector<string> possibleWords(int a[], int N)
    {
        map<int, string> mp;

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        vector<string> v;
        words(a, N, 0, "", v, mp);
        return v;
    }
};

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}