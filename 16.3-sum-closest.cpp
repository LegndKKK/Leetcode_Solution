/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, best = INT_MAX, n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < best)
                {
                    best = abs(sum - target);
                    ans = sum;
                }
                if (sum == target)
                    return target;
                else if (sum > target)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};
// @lc code=end
