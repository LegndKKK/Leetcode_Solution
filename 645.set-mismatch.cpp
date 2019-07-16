/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int dup = -1, missing = -1;
        for (int i : nums)
            if (nums[abs(i) - 1] < 0)
                dup = abs(i);
            else
                nums[abs(i) - 1] *= -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
            {
                missing = i + 1;
                break;
            }
        return {dup, missing};
    }
};
