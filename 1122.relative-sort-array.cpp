/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> m;
        for (auto i : arr1)
            m[i]++;
        vector<int> ans;
        for (auto i : arr2)
        {
            for (int j = 0; j < m[i]; j++)
                ans.push_back(i);
            m.erase(i);
        }
        int n = ans.size();
        auto it = m.begin();
        while (it != m.end())
        {
            for (int i = 0; i < it->second; i++)
                ans.push_back(it->first);
            it++;
        }
        sort(ans.begin() + n, ans.end());
        return ans;
    }
};
