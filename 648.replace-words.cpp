/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */
class Solution
{
public:
    string replaceWords(vector<string> &dict, string sentence)
    {
        unordered_set<string> s;
        for (string root : dict)
            s.insert(root);
        stringstream ss(sentence);
        string word;
        string ans = "";
        while (ss >> word)
        {
            string cur = "";
            for (int i = 0; i < word.size(); i++)
            {
                cur += word[i];
                if (s.find(cur) != s.end())
                {
                    word = cur;
                    break;
                }
            }
            ans += word + " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};
