#include <bits/stdc++.h>
using namespace std;

class comp
{
public:
    bool operator()(string &b, string &a)
    {
        if (a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    }
};

class Solution
{
public:
    string kthLargestNumber(vector<string> &nums, int k)
    {
        priority_queue<string, vector<string>, comp> heap;
        for (int i = 0; i < nums.size(); i++)
        {
            heap.push(nums[i]);
            if (heap.size() > k)
                heap.pop();
        }
        return heap.top();
    }
};

int main()
{
    Solution ob;
    vector<string> v = {"3", "6", "7", "10"} cout << ob.kthLargestNumber(v, 3) << endl;
    return 0;
}