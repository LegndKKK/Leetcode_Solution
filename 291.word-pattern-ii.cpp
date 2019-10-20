/*
 * @lc app=leetcode id=291 lang=cpp
 *
 * [291] Word Pattern II
 */
class Solution
{
public:
    bool wordPatternMatch(string pattern, string str)
    {
        int n = pattern.size(), m = str.size();
        if (n == 0 && m == 0)
            return true;
        if ((!n && m) || (n && !m) || (n > m))
            return false;

        //allpat store all current exist pattern, for check string to char
        unordered_set<string> allpat;
        //table[i] store the i's pattern, for check char to string
        vector<string> table(26, "");
        bool ans = false;

        function<bool(int, int)> dfs = [&](int curn, int curm) {
            //curn - current idx in pattern
            //curm - current idx in str
            if (curn >= n || curm >= m)
            {
                //matching
                if (curn == n && curm == m)
                    return true;
                return false;
            }

            int idx = pattern[curn] - 'a';
            //if current char has a pattern
            if (table[idx] != "")
            {
                int l = table[idx].size();
                //not match
                if (curm + l > m || str.substr(curm, l) != table[idx])
                    return false;
                //match, dfs for next
                return dfs(curn + 1, curm + l);
            }

            //loop for length of possible pattern
            //n-curn-1 because all remaining char in pattern needs at least 1
            for (int l = 1; l <= m - curm - (n - curn - 1); l++)
            {
                //pattern exists, continue
                if (allpat.find(str.substr(curm, l)) != allpat.end())
                    continue;
                string curpat = str.substr(curm, l);
                table[idx] = curpat;
                allpat.insert(curpat);
                //if true for the remaining, return true
                if (dfs(curn + 1, curm + l))
                {
                    allpat.erase(curpat);
                    table[idx] = "";
                    return true;
                }
                //backtracking
                allpat.erase(curpat);
                table[idx] = "";
            }
            return false;
        };
        ans = dfs(0, 0);
        return ans;
    }
};
//"aaaa"\n"asdasdasdasd"
//"aabb"\n"xyzabcxyzabc"
//"abab"\n"xyzabcxyzabc"
//""\n""
//"ab"\n"aa"
//"itwasthebestoftimes"\n"ittwaastthhebesttoofttimes"
//"itwasthebestoftimes"\n"ittwaastthhebesttoofttimesss"
