/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution
{
public:
    int reverse(int x)
    {
        int sign = 0;
        if (x == INT_MIN)
            return 0;
        if (x < 0)
        {
            sign = 1;
            x = abs(x);
        }
        vector<int> d;
        while (x > 0)
        {
            d.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0; i < d.size(); i++)
        {
            if (x > INT_MAX / 10)
                return 0;
            x *= 10;
            x += d[i];
        }
        return sign ? 0 - x : x;
    }
};
