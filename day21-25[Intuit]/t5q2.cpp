#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int pos)
    {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        if (pos == word.size())
            return true;

        if (word[pos] == board[i][j])
        {
            char temp = board[i][j];
            board[i][j] = '#';
            bool up = dfs(board, word, i + 1, j, pos + 1),
                 down = dfs(board, word, i - 1, j, pos + 1),
                 right = dfs(board, word, i, j + 1, pos + 1),
                 left = dfs(board, word, i, j - 1, pos + 1);

            board[i][j] = temp;
            return up || down || right || left;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    bool val = dfs(board, word, i, j, 0);
                    if (val)
                        return val;
                }
            }
        }
        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}