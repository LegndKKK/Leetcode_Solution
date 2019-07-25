/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> r(26, 0), m(26, 0);
        for (char c : ransomNote)
            r[c - 'a']++;
        for (char c : magazine)
            m[c - 'a']++;
        for (int i = 0; i < 26; i++)
            if (r[i] > m[i])
                return false;
        return true;
    }
};
