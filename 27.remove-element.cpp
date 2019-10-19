/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int cur = 0;
        for (int i : nums)
        {
            if (i != val)
            {
                nums[cur] = i;
                cur++;
            }
        }
        return cur;
    }
};
// @lc code=end
