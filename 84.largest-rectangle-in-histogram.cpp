/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<pair<int, int>> s;
        int n = heights.size(), ans = 0;
        vector<int> front(n, 0), back(n, 0);
        s.push({-1, -1});
        for (int i = 0; i < n; i++)
        {
            while (s.top().second >= heights[i])
                s.pop();
            front[i] = s.top().first;
            s.push({i, heights[i]});
        }
        while (!s.empty())
            s.pop();
        s.push({n, -1});
        for (int i = n - 1; i >= 0; i--)
        {
            while (s.top().second >= heights[i])
                s.pop();
            back[i] = s.top().first;
            s.push({i, heights[i]});
        }
        for (int i = 0; i < n; i++)
            ans = max(ans, heights[i] * (back[i] - front[i] - 1));
        return ans;
    }
};
