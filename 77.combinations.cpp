/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> cur;
        vector<vector<int>> ans;

        function<void(int)> dfs = [&](int num) {
            if (num == k)
            {
                ans.push_back(cur);
                return;
            }
            //num means the number in cur,
            //i starts from cur[num-1] +1 to n
            int begin = num > 0 ? cur[num - 1] : 0;
            for (int i = begin + 1; i <= n; i++)
            {
                cur.push_back(i);
                dfs(num + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
