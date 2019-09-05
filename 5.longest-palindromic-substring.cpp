/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s == "")
            return s;
        int n = s.size(), l = 1, front = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= min(i, n - 1 - i); j++)
            {
                if (s[i - j] == s[i + j])
                {
                    if (i - j > l)
                }
            }
        }
    }
};
