/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Paint House
 */
class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        if (!n)
            return 0;
        int dp[3] = {0}, pre[3] = {0};
        for (int i = 0; i < 3; i++)
            dp[i] = costs[0][i];
        for (int num = 1; num < n; num++)
        {
            pre[0] = dp[0];
            pre[1] = dp[1];
            pre[2] = dp[2];
            dp[0] = costs[num][0] + min(pre[1], pre[2]);
            dp[1] = costs[num][1] + min(pre[0], pre[2]);
            dp[2] = costs[num][2] + min(pre[0], pre[1]);
        }
        return min(min(dp[0], dp[1]), dp[2]);
    }
};
