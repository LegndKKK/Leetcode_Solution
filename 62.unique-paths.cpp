/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (!m || !n)
            return 0;
        vector<int> a(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                a[j] += a[j - 1];

        return a[n - 1];
    }
};
