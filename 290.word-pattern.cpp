/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<string, char> sc;
        unordered_map<char, string> cs;
        stringstream ss(str);
        string word;
        int i = 0;
        while (ss >> word)
        {
            //check if too many words
            if (i >= pattern.size())
                return false;
            char curc = pattern[i];
            if (cs.find(curc) == cs.end())
            {
                if (sc.find(word) != sc.end())
                    return false;
                cs[curc] = word;
                sc[word] = curc;
            }
            else
            {
                if (word != cs[curc])
                    return false;
            }
            i++;
        }
        //check if pattern char left
        if (i != pattern.size())
            return false;
        return true;
    }
};
//"abba"\n"dog cat cat dog"
// @lc code=end
