/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
class Solution
{
public:
    int myAtoi(string str)
    {
        int n = str.size(), i = 0, minus = 0;
        long long ans = 0;
        while (i < n && str[i] == ' ')
            i++;
        str = str.substr(i, n - i);
        n -= i;
        if (n > 0 && (str[0] == '-' || str[0] == '+'))
        {
            minus = str[0] == '-' ? 1 : 0;
            str = str.substr(1, n - 1);
            n--;
        }
        if (n < 1 || !(str[0] >= '0' && str[0] <= '9'))
            return 0;
        i = 0;
        while (i < n && str[i] >= '0' && str[i] <= '9')
        {
            ans *= 10;
            ans += (str[i] - '0');
            i++;
            if (minus && ans > INT_MAX)
                return INT_MIN;
            else if (!minus && ans >= INT_MAX)
                return INT_MAX;
        }
        return minus ? -ans : ans;
    }
};
