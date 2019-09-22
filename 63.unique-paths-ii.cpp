/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &a)
    {
        int r = a.size(), c = r > 0 ? a[0].size() : 0;
        if (!r || !c)
            return 0;
        vector<long long> count(c, 0);
        int firstrow = r;
        for (int i = 0; i < c; i++)
        {
            if (a[0][i] == 1)
                break;
            count[i] = 1;
        }
        for (int i = 0; i < r; i++)
        {
            if (a[i][0] == 1)
            {
                firstrow = i;
                break;
            }
        }
        for (int i = 1; i < r; i++)
        {
            if (i >= firstrow)
                count[0] = 0;
            else
                count[0] = 1;
            for (int j = 1; j < c; j++)
            {
                if (a[i][j] == 1)
                    count[j] = 0;
                else
                    count[j] += count[j - 1];
            }
        }
        return count[c - 1];
    }
};
