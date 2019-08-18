/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution
{
public:
    string countAndSay(int n)
    {
        string cur = "1";
        for (int i = 0; i < n - 1; i++)
        {
            string next = "";
            int count = 1;
            char last = cur[0];
            for (int k = 1; k < cur.size(); k++)
            {
                char c = cur[k];
                if (c == last)
                    count++;
                else
                {
                    next += to_string(count);
                    next += last;
                    count = 1;
                    last = c;
                }
            }
            next += to_string(count);
            next += last;
            cur = next;
        }
        return cur;
    }
};
