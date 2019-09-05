/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size(), ans = n + 1;
        for (int i = 0; i < n; i++)
        {
            int cur = nums[i];
            while (cur >= 1 && cur <= n)
            {
                int next = nums[cur - 1];
                nums[cur - 1] = INT_MIN;
                cur = next;
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != INT_MIN)
            {
                ans = i + 1;
                break;
            }
        return ans;
    }
};
