/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = INT_MAX;

        function<void(TreeNode *, int)> search = [&](TreeNode *x, int depth) {
            if (!x)
                return;
            if (!x->left && !x->right)
                ans = min(ans, depth);
            search(x->left, depth + 1);
            search(x->right, depth + 1);
        };
        search(root, 1);
        return ans;
    }
};
