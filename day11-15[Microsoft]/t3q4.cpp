#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> m, int r, int c)
    {
        // code here
        int rs = 0, re = r - 1, cs = 0, ce = c - 1;
        vector<int> v;
        while (rs <= re && cs <= ce)
        {
            for (int col = cs; col <= ce; col++)
            {
                v.push_back(m[rs][col]);
            }
            for (int row = rs + 1; row <= re; row++)
            {
                v.push_back(m[row][ce]);
            }
            for (int col = ce - 1; col >= cs; col--)
            {
                // cout<<"3\n";
                // cout<<m[re][col]<<" ";
                if (re == rs)
                    break;
                v.push_back(m[re][col]);
            }
            for (int row = re - 1; row >= rs + 1; row--)
            {
                if (ce == cs)
                    break;
                v.push_back(m[row][cs]);
            }
            rs++;
            cs++;
            re--;
            ce--;
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}