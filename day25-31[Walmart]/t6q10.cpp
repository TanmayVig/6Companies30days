#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    double r, x, y;
    Solution(double radius, double x_center, double y_center)
    {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint()
    {
        double angle = ((double)rand() / RAND_MAX) * 2 * M_PI,
               h = sqrt((double)rand() / RAND_MAX) * r,
               x_ = cos(angle) * h,
               y_ = sin(angle) * h;
        return vector<double>{x + x_, y + y_};
    }
};

int main()
{
    Solution obj(12.00, 9.0, 7.0);
    cout << obj.randPoint() << endl;
    return 0;
}
