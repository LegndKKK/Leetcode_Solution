/*
 * @lc app=leetcode id=265 lang=cpp
 *
 * [265] Paint House II
 */
class Solution
{
public:
    int minCostII(vector<vector<int>> &costs)
    {
        int premin = 0, premin2 = 0, preidx = -1;
        int n = costs.size(), k = n > 0 ? costs[0].size() : 0;
        if (!n || !k)
            return 0;

        for (int i = 0; i < n; i++)
        {
            int min = INT_MAX, min2 = INT_MAX, idx = 0;
            for (int j = 0; j < k; j++)
            {
                int temp = costs[i][j];
                temp += j == preidx ? premin2 : premin;
                if (temp <= min)
                {
                    min2 = min;
                    min = temp;
                    idx = j;
                }
                else if (temp < min2)
                {
                    min2 = temp;
                }
            }
            premin = min;
            premin2 = min2;
            preidx = idx;
        }

        return premin;
    }
};
