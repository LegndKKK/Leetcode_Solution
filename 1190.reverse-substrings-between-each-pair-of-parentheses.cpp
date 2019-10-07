/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> ss;
        if (s.size() < 2)
            return s;
        for (char c : s)
        {
            if (c == '(')
                ss.push(string(1, c));
            else if (c == ')')
            {
                if (!ss.empty() && ss.top() == "(")
                {
                    ss.pop();
                    continue;
                }
                string temp = ss.top();
                reverse(temp.begin(), temp.end());
                ss.pop();
                ss.pop();
                if (!ss.empty())
                {
                    temp = ss.top() + temp;
                    ss.pop();
                }
                ss.push(temp);
            }
            else
            {
                if (ss.empty() || (!s.empty() && ss.top() == "("))
                    ss.push(string(1, c));
                else
                {
                    string temp = ss.top();
                    ss.pop();
                    temp += c;
                    ss.push(temp);
                }
            }
        }
        return ss.top();
    }
};
// @lc code=end
