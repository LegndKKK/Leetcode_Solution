/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN, cum = 0;
        for (int i : nums)
        {
            cum += i;
            ans = max(ans, cum);
            if (cum < 0)
                cum = 0;
        }
        return ans;
    }
};
