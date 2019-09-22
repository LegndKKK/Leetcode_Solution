/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n3 != n1 + n2)
            return false;

        //dp[i][j] = 1, s1[0..i-1] and s2[0..j-1] can make s3[0..i+j-1]
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        dp[0][0] = 1;
        //initialize first row and column, means only one string
        for (int i = 0; i < n1; i++)
            if (s1[i] == s3[i])
                dp[i + 1][0] = 1;
            else
                break;
        for (int i = 0; i < n2; i++)
            if (s2[i] == s3[i])
                dp[0][i + 1] = 1;
            else
                break;
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                //if left or up element is 1, can lead to 1
                if ((dp[i - 1][j] == 1 && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]))
                    dp[i][j] = 1;

        return dp[n1][n2] == 1;
    }
};
//""\n""\n""
