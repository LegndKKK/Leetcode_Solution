/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
class Solution
{
public:
    int minPathSum(vector<vector<int>> &g)
    {
        int r = g.size(), c = r > 0 ? g[0].size() : 0;
        if (!r || !c)
            return 0;
        //1D array needed to store minimum of each columnn
        vector<int> count(c, 0);
        count[0] = g[0][0];
        for (int i = 1; i < c; i++)
            count[i] = count[i - 1] + g[0][i];
        for (int i = 1; i < r; i++)
        {
            //count[0] is first row, it has only one path
            count[0] += g[i][0];
            for (int j = 1; j < c; j++)
                count[j] = min(count[j], count[j - 1]) + g[i][j];
        }
        return count[c - 1];
    }
};
