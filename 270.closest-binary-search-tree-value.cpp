/*
 * @lc app=leetcode id=270 lang=cpp
 *
 * [270] Closest Binary Search Tree Value
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int closestValue(TreeNode *root, double target)
    {
        int ans = 0;
        double dif = (double)(LLONG_MAX);
        TreeNode *cur = root;
        while (cur)
        {
            double curval = (double)(cur->val);
            if (abs(curval - target) < dif)
            {
                dif = abs(curval - target);
                ans = cur->val;
            }
            if (curval > target)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return ans;
    }
};
// @lc code=end
//[2147483647]\n0.0