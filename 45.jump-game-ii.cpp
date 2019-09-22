/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        //bfs, search in [minpos, maxpos]
        int n = nums.size(), count = 0, minpos = 0, maxpos = 0;
        while (maxpos < n - 1)
        {
            count++;
            int temp = maxpos;
            for (int i = minpos; i <= maxpos; i++)
            {
                temp = max(temp, i + nums[i]);
                if (temp >= n - 1)
                    return count;
            }
            minpos = maxpos + 1;
            maxpos = temp;
        }
        return count;
    }
};
