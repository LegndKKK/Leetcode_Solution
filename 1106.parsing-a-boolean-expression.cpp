/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */
class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        if (expression == "t")
            return true;
        if (expression == "f")
            return false;
        if (expression[0] == '!')
            return !parseBoolExpr(expression.substr(2, expression.size() - 3));
        bool ans = true;
        int count = 0, last = 2;
        vector<bool> sub;
        for (int i = 2; i < expression.size() - 1; i++)
        {
            if (expression[i] == '(')
                count++;
            else if (expression[i] == ')')
                count--;
            else if (count == 0 && expression[i] == ',')
            {
                sub.push_back(parseBoolExpr(expression.substr(last, i - last)));
                last = i + 1;
            }
        }
        sub.push_back(parseBoolExpr(expression.substr(last, expression.size() - 1 - last)));
        if (expression[0] == '&')
        {
            ans = true;
            for (auto i : sub)
                ans &= i;
        }
        else
        {
            ans = false;
            for (auto i : sub)
                ans |= i;
        }

        return ans;
    }
};
