/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 */

// @lc code=start
class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        vector<set<int>> in(26), out(26);
        int visit[26] = {0}, left = 0;
        string ans = "";
        for (string s : words)
            for (char c : s)
                visit[c - 'a'] = 1;
        for (int i = 0; i < words.size() - 1; i++)
        {
            string str1 = words[i];
            string str2 = words[i + 1];
            for (int j = 0; j < min(str1.size(), str2.size()); j++)
            {
                if (str1[j] != str2[j])
                {
                    in[str2[j] - 'a'].insert(str1[j] - 'a');
                    out[str1[j] - 'a'].insert(str2[j] - 'a');
                    break;
                }
            }
        }
        for (int i : visit)
            if (i)
                left++;
        while (true)
        {
            bool flag = false;
            for (int i = 0; i < 26; i++)
            {
                if (visit[i] && in[i].size() == 0)
                {
                    ans += (char)(i + 'a');
                    auto it = out[i].begin();
                    while (it != out[i].end())
                    {
                        in[(*it)].erase(i);
                        it++;
                    }
                    visit[i] = 0;
                    flag = true;
                    left--;
                    if (left == 0)
                        return ans;
                }
            }
            if (!flag)
                return "";
        }

        return ans;
    }
};
// @lc code=end
