/*
 * @lc app=leetcode id=1169 lang=cpp
 *
 * [1169] Invalid Transactions
 */

// @lc code=start
class Solution
{
public:
    struct item
    {
        int idx;
        int time;
        int amount;
        int added;
        string loc;
    };
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        vector<string> ans;
        unordered_map<string, vector<item>> m;
        for (int i = 0; i < transactions.size(); i++)
        {
            string s = transactions[i];
            size_t pos1 = s.find(',');
            string name = s.substr(0, pos1);
            item cur;
            cur.idx = i;
            size_t pos2 = s.find(',', pos1 + 1);
            cur.time = stoi(s.substr(pos1 + 1, pos2 - pos1 - 1));
            pos1 = pos2;
            pos2 = s.find(',', pos1 + 1);
            cur.amount = stoi(s.substr(pos1 + 1, pos2 - pos1 - 1));
            cur.loc = s.substr(pos2 + 1, s.size() - 1 - pos2);
            if (cur.amount > 1000)
            {
                cur.added = 1;
                ans.push_back(s);
            }
            else
                cur.added = 0;
            if (m.find(name) != m.end())
            {
                m[name].push_back(cur);
            }
            else
            {
                vector<item> temp;
                temp.push_back(cur);
                m[name] = temp;
            }
            for (auto it = m[name].begin(); it != m[name].end(); it++)
            {
                if (it->idx != i && it->loc != cur.loc && abs(it->time - cur.time) <= 60)
                {
                    if (it->added == 0)
                    {
                        ans.push_back(transactions[it->idx]);
                        it->added = 1;
                    }
                    if (cur.added == 0)
                    {
                        cur.added = 1;
                        ans.push_back(s);
                        m[name][m[name].size() - 1].added = 1;
                    }
                }
            }
        }
        return ans;
    }
};
//["alice,20,800,mtv","alice,50,100,beijing","alice,20,800,mtv","alice,50,1200,mtv"]
//["alice,20,800,mtv","alice,50,1200,mtv"]
// @lc code=end
