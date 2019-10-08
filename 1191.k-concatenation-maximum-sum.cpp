/*
 * @lc app=leetcode id=1191 lang=cpp
 *
 * [1191] K-Concatenation Maximum Sum
 */

// @lc code=start
class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        int sum = 0, n = arr.size(), ans = 0, cum = 0, maxl = 0, maxr = 0, div = 1000000007;
        for (int i : arr)
        {
            i %= div;
            sum += i;
            sum %= div;
            maxl = max(maxl, sum);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            cum += arr[i];
            cum %= div;
            maxr = max(maxr, cum);
        }
        if (sum < 0)
        {
            cum = 0;
            for (int i : arr)
            {
                cum += i;
                cum %= div;
                ans = max(ans, cum);
                if (cum < 0)
                    cum = 0;
            }
            if (k >= 2)
                ans = max(ans, maxl + maxr);
            if (ans < 0)
                ans = 0;
        }
        else
        {
            if (sum > 0 && INT_MAX / sum < k - 2)
            {
                for (int i = 0; i < k - 2; i++)
                {
                    ans += sum;
                    ans %= div;
                }
            }
            else
                ans = (k - 2) * sum;
            ans %= div;
            ans += maxl;
            ans += maxr;
            ans %= div;
        }
        return ans;
    }
};
// @lc code=end
