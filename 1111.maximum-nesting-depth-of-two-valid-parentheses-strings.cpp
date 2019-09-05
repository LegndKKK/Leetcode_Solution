/*
 * @lc app=leetcode id=1111 lang=cpp
 *
 * [1111] Maximum Nesting Depth of Two Valid Parentheses Strings
 */
class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> ans;
        stack<int> s;
        //int maxn = 0, cur = 0;
        // for (char c : seq)
        //     if (c == '(')
        //     {
        //         s.push(cur);
        //         cur++;
        //         maxn = max(maxn, cur);
        //     }
        //     else
        //     {
        //         s.pop();
        //         cur--;
        //     }
        // //cout << maxn << endl;
        // maxn = (maxn + 1) / 2;
        int cur = 0;
        for (char c : seq)
            if (c == '(')
            {
                s.push(cur);
                if (cur % 2 == 0)
                    ans.push_back(0);
                else
                    ans.push_back(1);
                cur++;
            }
            else
            {
                if (s.top() % 2 == 0)
                    ans.push_back(0);
                else
                    ans.push_back(1);
                s.pop();
                cur--;
            }
        return ans;
    }
};
//"(()())((()))"
