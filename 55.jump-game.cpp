/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size(), maxpos = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= maxpos)
                maxpos = i;
        }
        return maxpos == 0;
    }
};
