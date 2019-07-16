/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */
class Solution
{
public:
    string predictPartyVictory(string s)
    {
        int n = s.size(), r = 0, d = 0;
        vector<int> remain(n, 0);
        for (int i = 0; i < n; i++)
            if (s[i] == 'R')
                r++;
            else
                d++;

        function<int(int, char)> idx = [&](int start, char flag) {
            for (int i = start + 1; i < n; i++)
                if (s[i] != flag && remain[i] == 0)
                    return i;
            for (int i = 0; i < start; i++)
                if (s[i] != flag && remain[i] == 0)
                    return i;
            return -1;
        };
        int cur = -1;
        while (true)
        {
            cur++;
            cur %= n;
            if (remain[cur] != 0)
                continue;
            if (s[cur] == 'R' && d == 0)
                return "Radiant";
            if (s[cur] == 'D' && r == 0)
                return "Dire";
            int pick = idx(cur, s[cur]);
            if (pick != -1)
            {

                remain[pick] = 1;
                if (s[cur] == 'R')
                    d--;
                else
                    r--;
            }
        }
        return "";
    }
};
