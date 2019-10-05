/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &h)
    {
        int n = h.size(), l = 0, r = n - 1, ans = 0;
        if (n < 2)
            return 0;
        while (l < r)
        {
            ans = max(ans, (r - l) * min(h[l], h[r]));
            if (h[l] > h[r] || (h[l] == h[r] && h[l + 1] > h[r - 1]))
                r--;
            else
                l++;
        }
        return ans;
    }
};
// @lc code=end
