/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int count[26] = {0};
        for (char c : text)
            count[c - 'a']++;
        int a = min(min(count[0], count[1]), count['n' - 'a']);
        int b = min(count['l' - 'a'], count['o' - 'a']) / 2;
        return min(a, b);
    }
};
// @lc code=end
