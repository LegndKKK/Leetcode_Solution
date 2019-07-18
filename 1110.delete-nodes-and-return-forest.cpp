/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        unordered_set<int> s;
        for (int i : to_delete)
            s.insert(i);

        function<void(TreeNode *)> preorder = [&](TreeNode *x) {
            if (!x)
                return;
            preorder(x->left);
            if (x->left && s.find(x->left->val) != s.end())
                x->left = NULL;
            preorder(x->right);
            if (x->right && s.find(x->right->val) != s.end())
                x->right = NULL;
            if (s.find(x->val) != s.end())
            {
                if (x->left && s.find(x->left->val) == s.end())
                    ans.push_back(x->left);
                if (x->right && s.find(x->right->val) == s.end())
                    ans.push_back(x->right);
                x->left = NULL;
                x->right = NULL;
            }
        };
        preorder(root);
        if (s.find(root->val) == s.end())
            ans.push_back(root);
        return ans;
    }
};
