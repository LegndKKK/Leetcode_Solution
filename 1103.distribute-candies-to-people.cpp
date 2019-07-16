/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */
class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> ans(num_people, 0);
        int count = 0;
        while (candies > 0)
        {
            //count % num_people is the number distributed
            count++;
            if (candies > count)
                ans[(count - 1) % num_people] += count;
            else
                ans[(count - 1) % num_people] += candies;
            candies -= count;
        }
        return ans;
    }
};
