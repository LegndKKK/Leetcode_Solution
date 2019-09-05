/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size(), cur = -1, count = 0, i = 0;
        while (cur < n)
        {
            cur++;
            if (arr[cur] == 0)
                count++;
            if (cur + count >= n - 1)
                break;
        }
        if (cur + 1 + count == n)
        {
            i = n - 1;
        }
        else
        {
            arr[n - 1] = 0;
            cur--;
            i = n - 2;
        }
        while (cur >= 0)
        {
            if (arr[cur] == 0)
            {
                arr[i--] = 0;
                arr[i--] = 0;
            }
            else
                arr[i--] = arr[cur];
            cur--;
        }
    }
};
