/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if (!n)
            return ans;
        int curx = 0, cury = n - 1, l = n - 1, dir = 0, cur = n;
        int d[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        for (int i = 0; i < n; i++)
            ans[0][i] = i + 1;
        while (l > 0)
        {
            dir %= 4;
            for (int i = 0; i < l; i++)
            {
                cur++;
                curx += d[dir][0];
                cury += d[dir][1];
                ans[curx][cury] = cur;
            }
            dir++;
            if (dir % 2 == 0)
                l--;
        }
        return ans;
    }
};
