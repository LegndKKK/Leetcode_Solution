/*
 * @lc app=leetcode id=1170 lang=cpp
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 */

// @lc code=start
class Solution
{
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> wcount, ans;
        for (string s : words)
        {
            int count[26] = {0};
            for (char c : s)
                count[c - 'a']++;
            for (int i : count)
                if (i > 0)
                {
                    wcount.push_back(i);
                    break;
                }
        }
        sort(wcount.begin(), wcount.end(), greater<int>());

        for (string s : queries)
        {
            int count[26] = {0}, curcount = 0;
            for (char c : s)
                count[c - 'a']++;
            for (int i : count)
                if (i > 0)
                {
                    curcount = i;
                    break;
                }
            //Binary search to find the last number larger then curcount
            int l = 0, r = wcount.size() - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (wcount[mid] <= curcount)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            ans.push_back(r + 1);
        }
        return ans;
    }
};
// @lc code=end
