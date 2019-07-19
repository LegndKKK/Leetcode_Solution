/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int start[1000] = {0}, end[1000] = {0};
        int cur = 0;
        for (auto i : trips)
        {
            start[i[1]] += i[0];
            end[i[2]] += i[0];
        }
        for (int i = 0; i < 1000; i++)
        {
            cur -= end[i];
            if (cur < 0)
                cur = 0;
            cur += start[i];
            if (cur > capacity)
                return false;
        }
        return true;
    }
};
