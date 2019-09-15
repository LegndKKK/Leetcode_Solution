/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        if (n == 0)
            return 0;
        if (citations[0] >= n)
            return n;
        for (int i = n - 1; i > 0; i--)
        {
            if (citations[i] >= n - i && citations[i - 1] <= n - i)
                return n - i;
        }
        return 0;
    }
};
