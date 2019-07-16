/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1;
        int r = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid) == false)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
