/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), ans = 0, maxh = 0;
        vector<int> l(n, 0), r(n, 0);
        for (int i = 0; i < n; i++)
        {
            maxh = max(maxh, height[i]);
            l[i] = maxh;
        }
        maxh = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            maxh = max(maxh, height[i]);
            r[i] = maxh;
        }
        for (int i = 0; i < n; i++)
            ans += (min(l[i], r[i]) - height[i]);
        return ans;
    }
};
// @lc code=end
