/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 * 
 */
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size(), pos = -1;
        while (s[n - 1] == ' ' && n > 0)
            n--;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
            return n;
        else
            return n - pos - 1;
        return 0;
    }
};
