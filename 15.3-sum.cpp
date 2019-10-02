/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 3)
            return ans;
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1, target = 0 - nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < n - 1 && nums[j] == nums[j - 1])
                        j++;
                }
                else if (nums[j] + nums[k] > target)
                {
                    k--;
                    while (k > i + 1 && nums[k] == nums[k + 1])
                        k--;
                }
                else
                {
                    j++;
                    while (j < n - 1 && nums[j] == nums[j - 1])
                        j++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
