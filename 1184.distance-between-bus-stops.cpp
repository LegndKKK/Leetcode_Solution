/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

// @lc code=start
class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        if (start == destination)
            return 0;
        if (start > destination)
            return distanceBetweenBusStops(distance, destination, start);
        int totalsum = 0, sum = 0;
        for (int i = 0; i < distance.size(); i++)
        {
            totalsum += distance[i];
            if (i >= start && i < destination)
                sum += distance[i];
        }
        return min(sum, totalsum - sum);
    }
};
// @lc code=end
