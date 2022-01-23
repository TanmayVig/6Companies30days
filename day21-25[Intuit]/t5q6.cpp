#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int bin_search(int target, MountainArray &arr, int l, int r)
    {
        int mid = (l + r) / 2;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int ele = arr.get(mid);
            // cout << mid << ": " << ele << endl;
            if (ele == target)
                return mid;
            else if (ele < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int bin_search_rev(int target, MountainArray &arr, int l, int r)
    {
        int mid = (l + r) / 2;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int ele = arr.get(mid);
            // cout << mid << ": " << ele << endl;
            if (ele == target)
                return mid;
            else if (ele < target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &marr)
    {
        // peak
        int l = 0, r = marr.length() - 1;
        int mid = (r + l) / 2;
        int left_e, right_e, mid_e;
        int peak;
        while (r >= l)
        {
            mid = (r + l) / 2;

            mid_e = marr.get(mid);
            left_e = 0;
            right_e = 1e9;
            if (mid > 0)
                left_e = marr.get(mid - 1);
            if (mid < marr.length() - 1)
                right_e = marr.get(mid + 1);

            if (mid_e > left_e && mid_e > right_e)
            {
                // cout<<mid<<endl;

                break;
            }
            else if (mid_e < right_e)
                l = mid + 1;
            else if (mid_e < left_e)
                r = mid - 1;
        }

        // cout << "Peak: " << mid << endl;

        int left_i = bin_search(target, marr, 0, mid),
            right_i = bin_search_rev(target, marr, mid, marr.length() - 1);
        // right_e=marr.get(*right_lb); left_e = marr.get(*left_lb);
        cout << left_i << " " << right_i << endl;
        if (left_i != -1)
            return left_i;
        else if (right_i != -1)
            return right_i;
        return -1;
    }
};