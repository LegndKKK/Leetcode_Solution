/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first > b.first;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size(), left = 0;
        vector<ListNode *> curl = lists;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        ListNode *head = new ListNode(0),
                 *cur = head;
        if (!k)
            return NULL;
        if (k == 1)
            return lists[0];
        for (int i = 0; i < k; i++)
            if (lists[i])
            {
                pq.push({lists[i]->val, i});
                left++;
            }
        while (left)
        {
            int curidx = pq.top().second;
            pq.pop();
            cur->next = curl[curidx];
            cur = cur->next;
            if (curl[curidx]->next)
            {
                curl[curidx] = curl[curidx]->next;
                pq.push({curl[curidx]->val, curidx});
            }
            else
                left--;
        }
        return head->next;
    }
};
// @lc code=end
