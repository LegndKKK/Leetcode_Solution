/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */
class Solution
{
public:
    int hIndex(vector<int> &c)
    {
        //Hashing Time = O(n), Space = O(n)
        int n = c.size(), cum = 0;
        if (!n)
            return 0;
        //Replace all c[i]>n as n
        vector<int> count(n + 1, 0);
        for (int i : c)
            if (i >= n)
                count[n]++;
            else
                count[i]++;
        if (count[0] == n)
            return 0;
        for (int i = n; i > 0; i--)
        {
            //cum stores the num from n to i+1, cum + count[i] means at least i
            //n - cum means no more than i
            if (cum + count[i] >= i && n - cum >= n - i)
                return i;
            cum += count[i];
        }
        return -1;

        //Sorting Time = O(nlogn), Space = O(1)
        // int n = c.size();
        // if (!n)
        //     return 0;
        // sort(c.begin(), c.end(), greater<int>());
        // if (c[0] == 0)
        //     return 0;
        // if (c[n - 1] >= n)
        //     return n;
        // for (int i = 0; i < n - 1; i++)
        //     if (c[i] >= i + 1 && c[i + 1] <= i + 1)
        //         return i + 1;
        // return -1;
    }
};
