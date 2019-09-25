/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size(), last = 0, cur = 1, ans = 0;
        if (n < 2)
            return n;
        last = nums[0];
        while (cur < n)
        {
            if (nums[cur] != last)
            {
                ans++;
                last = nums[cur];
                nums[ans] = last;
            }
            cur++;
        }
        return ans + 1;
    }
};
