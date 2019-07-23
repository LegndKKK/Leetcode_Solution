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
    }
};
