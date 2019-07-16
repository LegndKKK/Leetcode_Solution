/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    int maxDepth(Node *root)
    {
        int ans = 0;
        function<void(Node *, int)> dfs = [&](Node *x, int depth) {
            if (!x)
                return;
            bool isleaf = 1;
            for (auto i : x->children)
                if (i)
                {
                    isleaf = 0;
                    break;
                }
            if (isleaf)
                ans = max(ans, depth);
            for (auto i : x->children)
                dfs(i, depth + 1);
        };
        dfs(root, 1);
        return ans;
    }
};
