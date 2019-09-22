/*
 * @lc app=leetcode id=272 lang=cpp
 *
 * [272] Closest Binary Search Tree Value II
 */
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
    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        vector<int> ans;
        deque<int> maxq, minq;
        function<void(TreeNode *)> dfs = [&](TreeNode *x) {
            if (!x)
                return;
            dfs(x->left);
            if (x->val <= target)
            {
                minq.push_back(x->val);
                while (minq.size() > k)
                    minq.pop_front();
            }
            else
            {
                maxq.push_front(x->val);
                while (maxq.size() > k)
                    maxq.pop_back();
            }
            dfs(x->right);
        };

        dfs(root);
        if (target - (double)minq[0] <= (double)maxq[k - 1] - target)
        {
            for (int i : minq)
                ans.push_back(i);
        }

        return ans;
    }
};
