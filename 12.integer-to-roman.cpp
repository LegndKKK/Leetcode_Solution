/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<string> m = {"IVX", "XLC", "CDM"};
        string ans = "";
        int d = -1, temp = num;
        while (temp > 0)
        {
            d++;
            temp /= 10;
        }
        if (d == 3)
        {
            for (int i = 0; i < num / 1000; i++)
                ans += 'M';
            d--;
        }
        while (d >= 0)
        {
            int t = pow(10, d);
            int cur = (num / t) % 10;
            if (cur == 4 || cur == 9)
            {
                ans += m[d][0];
                ans += cur == 4 ? m[d][1] : m[d][2];
            }
            else if (cur != 0)
            {
                if (cur >= 5)
                    ans += m[d][1];
                for (int i = 0; i < cur % 5; i++)
                    ans += m[d][0];
            }
            d--;
        }
        return ans;
    }
};
// @lc code=end
