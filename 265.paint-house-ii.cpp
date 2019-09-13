/*
 * @lc app=leetcode id=265 lang=cpp
 *
 * [265] Paint House II
 */
class Solution
{
public:
    int minCostII(vector<vector<int>> &costs)
    {
        // int min1 = INT_MAX, min2 = INT_MAX, ans = INT_MAX;
        // int row1 = 0, row2 = 0;
        int ans = INT_MAX;
        vector<int> pre, cur;
        int n = costs.size(), k = n > 0 ? costs[0].size() : 0;
        if (!n || !k)
            return 0;

        function<vector<int>(vector<int>)> searchmin = [](vector<int> arr) {
            vector<int> ret(4, INT_MAX);
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] < ret[0])
                {
                    ret[2] = ret[0];
                    ret[3] = ret[1];
                    ret[0] = arr[i];
                    ret[1] = i;
                }
                else if (arr[i] < ret[2])
                {
                    ret[2] = arr[i];
                    ret[3] = i;
                }
            return ret;
        };

        pre = searchmin(costs[0]);

        for (int num = 1; num < n; num++)
        {
            cur = searchmin(costs[num]);
            //cout << pre[0] << cur[0] << endl;
            vector<pair<int, int>> temp;
            if (cur[1] != pre[1])
                temp.push_back({cur[0] + pre[0], cur[1]});
            if (cur[3] != pre[1])
                temp.push_back({cur[2] + pre[0], cur[3]});
            if (cur[1] != pre[3])
                temp.push_back({cur[0] + pre[2], cur[1]});
            if (cur[3] != pre[3])
                temp.push_back({cur[2] + pre[2], cur[1]});
            //for (auto i : temp)
            //    cout << i.first << " " << i.second << endl;
            sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
            pre[0] = temp[0].first;
            pre[1] = temp[0].second;
            pre[2] = temp[1].first;
            pre[3] = temp[1].second;
        }
        return pre[0];
    }
};
