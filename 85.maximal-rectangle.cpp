/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int r = matrix.size(), c = r > 0 ? matrix[0].size() : 0, ans = 0;
        if (!r || !c)
            return 0;
        vector<int> hist(c, 0), front(c, 0), end(c, 0);
        ;
        for (int i = 0; i < r; i++)
        {
            front.assign(c, 0);
            end.assign(c, 0);
            for (int j = 0; j < c; j++)
                hist[j] = matrix[i][j] == '1' ? hist[j] + 1 : 0;

            stack<pair<int, int>> s;
            s.push({-1, -1});
            for (int j = 0; j < c; j++)
            {
                while (hist[j] <= s.top().second)
                    s.pop();
                front[j] = s.top().first;
                s.push({j, hist[j]});
            }
            while (!s.empty())
                s.pop();
            s.push({c, -1});
            for (int j = c - 1; j >= 0; j--)
            {
                while (hist[j] <= s.top().second)
                    s.pop();
                end[j] = s.top().first;
                s.push({j, hist[j]});
            }
            for (int j = 0; j < c; j++)
                ans = max(ans, hist[j] * (end[j] - front[j] - 1));
        }
        return ans;
    }
};
