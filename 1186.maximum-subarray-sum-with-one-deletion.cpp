/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 */

// @lc code=start
class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 2)
            return arr[0];
        //max if deleted or not
        int max_deleted = INT_MIN, max_nodeleted = INT_MIN;
        //init, assume delete first one, so cum_deleted=0
        //check if arr[0]<0 cum_nodeleted=0
        int cum_deleted = 0, cum_nodeleted = arr[0] > 0 ? arr[0] : 0;
        //loop from 1
        for (int i = 1; i < n; i++)
        {
            //deleted + arr[i]
            cum_deleted += arr[i];
            //compare cum_nodeleted(assume delete arr[i])
            //and cum_deleted(already deleted before arr[i])
            cum_deleted = max(cum_deleted, cum_nodeleted);
            cum_nodeleted += arr[i];
            //update max
            max_deleted = max(max_deleted, cum_deleted);
            max_nodeleted = max(max_nodeleted, cum_nodeleted);
            //if <0, reset to 0
            if (cum_nodeleted < 0)
                cum_nodeleted = 0;
            if (cum_deleted < 0)
                cum_deleted = 0;
        }
        //if all <0, then all negative, find the max
        if (max_deleted <= 0 && max_nodeleted <= 0)
        {

            max_nodeleted = INT_MIN;
            for (int i : arr)
                max_nodeleted = max(max_nodeleted, i);
            return max_nodeleted;
        }
        return max(max_deleted, max_nodeleted);
    }
};
// @lc code=end
