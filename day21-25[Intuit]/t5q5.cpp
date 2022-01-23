#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> nums, int m, int max)
    {
        long long int sum = 0;
        for (auto num : nums)
        {
            if (num > max)
                return false;
            else if (num + sum <= max)
                sum += num;
            else
            {
                m--;
                if (m == 0)
                    return false;
                sum = num;
            }
        }
        return true;
    }
    int splitArray(vector<int> &nums, int m)
    {

        long long int left = 0, right = 0;

        for (auto num : nums)
        {
            left = (left < num) ? num : left;
            right += num;
        }

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (check(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;
    cout << obj.splitArray(nums, m) << endl;
    return 0;
}