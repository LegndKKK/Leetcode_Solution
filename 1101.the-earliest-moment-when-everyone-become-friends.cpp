/*
 * @lc app=leetcode id=1101 lang=cpp
 *
 * [1101] The Earliest Moment When Everyone Become Friends
 */
class Solution
{
public:
    int remain = 0;
    vector<int> sz, p;
    int myfind(int x)
    {
        while (x != p[x])
        {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }

    void myunion(int x, int y)
    {
        int px = myfind(x);
        int py = myfind(y);
        if (px == py)
            return;
        if (sz[px] > sz[py])
        {
            p[py] = px;
            sz[px] += sz[py];
        }
        else
        {
            p[px] = py;
            sz[py] += sz[px];
        }
        remain--;
        return;
    }

    int earliestAcq(vector<vector<int>> &logs, int N)
    {
        remain = N;
        sort(logs.begin(), logs.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        sz.assign(N, 1);
        for (int i = 0; i < N; i++)
            p.push_back(i);
        for (int i = 0; i < logs.size(); i++)
        {
            myunion(logs[i][1], logs[i][2]);
            if (remain == 1)
                return logs[i][0];
        }
        return -1;
    }
};