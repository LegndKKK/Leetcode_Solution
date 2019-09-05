/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n < 2)
            return n;
        int front = 0, end = -1, ans = 1;
        int count[128] = {0};
        while (end < n - 1)
        {
            count[s[++end]]++;
            if (count[s[end]] > 1)
            {
                while (count[s[end]] > 1)
                {
                    count[s[front]]--;
                    front++;
                }
            }
            ans = max(ans, end - front + 1);
        }
        return ans;
    }
};
