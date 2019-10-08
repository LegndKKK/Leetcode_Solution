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
            //""+c is not converting a char to string!!!!
            if (c == '(')
                ss.push(string(1, c));
            else if (c == ')')
            {
                //check if top = "(", just pop
                if (!ss.empty() && ss.top() == "(")
                {
                    ss.pop();
                    continue;
                }
                //top is string, reverse
                string temp = ss.top();
                reverse(temp.begin(), temp.end());
                //pop string and (
                ss.pop();
                ss.pop();
                //if top is string, combine two strings
                if (!ss.empty() && ss.top() != "(")
                {
                    temp = ss.top() + temp;
                    ss.pop();
                }
                //push new string into stack
                ss.push(temp);
            }
            else
            {
                //if empty or first character
                if (ss.empty() || (!s.empty() && ss.top() == "("))
                    ss.push(string(1, c));
                else
                {
                    //if top is stirng, add char to the end of string
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
