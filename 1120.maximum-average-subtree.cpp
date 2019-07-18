/*
 * @lc app=leetcode id=1120 lang=cpp
 *
 * [1120] Maximum Average Subtree
 */
/**
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
    double maximumAverageSubtree(TreeNode *root)
    {
        double ans = 0;

        function<pair<int, int>(TreeNode *)> pre = [&](TreeNode *x) {
            if (!x)
                return make_pair(0, 0);
            auto [lsum, lnum] = pre(x->left);
            auto [rsum, rnum] = pre(x->right);
            int sum = lsum + x->val + rsum;
            int num = lnum + 1 + rnum;
            ans = max(ans, (double)(sum) / (double)(num));
            return make_pair(sum, num);
        };

        auto [sum, num] = pre(root);
        ans = max(ans, (double)(sum) / (double)(num));
        return ans;
    }
};
