/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int count[26] = {0}, cur[26] = {0}, unmatched = 0;
        vector<int> ans;
        if (words.size() == 0 || s == "")
            return ans;
        unordered_map<string, int> m;
        for (string str : words)
        {
            for (char c : str)
                count[c - 'a']++;
            m[str]++;
        }
        int length = words[0].size();
        int totallength = words.size() * length;
        if (s.size() < totallength)
            return ans;
        for (int i = 0; i < totallength; i++)
            cur[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (cur[i] != count[i])
                unmatched++;

        function<bool(int)> check = [&](int start) {
            unordered_map<string, int> curm = m;
            for (int idx = start; idx < start + totallength; idx += length)
            {
                string curstr = s.substr(idx, length);
                if (m.find(curstr) == m.end())
                    return false;
                curm[curstr]--;
            }
            auto it = curm.begin();
            while (it != curm.end())
            {
                if (it->second != 0)
                    return false;
                it++;
            }
            return true;
        };
        if (unmatched == 0 && check(0))
            ans.push_back(0);

        for (int i = 0; i < s.size() - totallength; i++)
        {
            int temp = s[i] - 'a';
            cur[temp]--;
            if (cur[temp] == count[temp])
                unmatched--;
            else if (cur[temp] == count[temp] - 1)
                unmatched++;
            temp = s[i + totallength] - 'a';
            cur[temp]++;
            if (cur[temp] == count[temp])
                unmatched--;
            else if (cur[temp] == count[temp] + 1)
                unmatched++;
            //cout << i << " " << unmatched << endl;
            if (unmatched == 0 && check(i + 1))
                ans.push_back(i + 1);
        }
        return ans;
    }
};
