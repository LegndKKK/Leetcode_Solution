/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            //check if dup, need chekc i>0
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                //check if dup, need check j>i+1
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;
                int sum = nums[i] + nums[j], k = j + 1, l = n - 1;
                while (k < l)
                {
                    if (sum + nums[k] + nums[l] == target)
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    if (sum + nums[k] + nums[l] < target)
                    {
                        while (k < l - 1 && nums[k] == nums[k + 1])
                            k++;
                        k++;
                    }
                    else
                    {
                        while (l > k + 1 && nums[l] == nums[l - 1])
                            l--;
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
