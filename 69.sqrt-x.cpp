/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;
        long long cur = 1, cum = 0;
        do
        {
            cur = 1;
            while ((cum + cur) * (cum + cur) < x)
                cur <<= 1;
            if ((cum + cur) * (cum + cur) == x)
                return (cum + cur);
            else
                cur >>= 1;
            cum += cur;
        } while ((cum + 1) * (cum + 1) <= x);
        return cum;
    }
};
