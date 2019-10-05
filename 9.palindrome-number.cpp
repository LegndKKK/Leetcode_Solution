/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int d = 0, a = x, m = 1, n = 10;
        while (a > 0)
        {
            a /= 10;
            d++;
        }
        m = pow(10, d - 1);
        for (int i = 0; i < d / 2; i++)
        {
            int front = x / m < 10 ? x / m : (x / m) % 10;
            int end = (x % n) / (n / 10);
            if (front != end)
                return false;
            m /= 10;
            n *= 10;
        }
        return true;
    }
};
// @lc code=end
