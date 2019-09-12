/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ans = "";
        if (numRows == 1)
            return s;
        int cur = 0, p = 2 * (numRows - 1), n = s.size();
        for (int i = 0; i < numRows; i++)
        {
            int idx = i;
            if (i == 0 || i == numRows - 1)
            {
                while (idx < n)
                {
                    ans += s[idx];
                    idx += p;
                }
            }
            else
            {
                while (idx < n)
                {
                    ans += s[idx];
                    idx += (p - 2 * i);
                    if (idx >= n)
                        break;
                    ans += s[idx];
                    idx += 2 * i;
                }
            }
        }
        return ans;
    }
};
