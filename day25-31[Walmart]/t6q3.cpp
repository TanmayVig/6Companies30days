#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        if (colors.size() < 3)
            return false;
        int count_a = 0, count_b = 0;
        for (int i = 0, j = 1, k = 2; k < colors.size(); i++, j++, k++)
        {
            if (colors[i] == colors[j] && colors[k] == colors[j])
            {
                if (colors[i] == 'A')
                    count_a++;
                else
                    count_b++;
            }
        }
        return count_a > count_b;
    }
};

int main()
{
    Solution obj;
    cout << obj.winnerOfGame("AAABBBAABABAAB") << endl;
    return 0;
}