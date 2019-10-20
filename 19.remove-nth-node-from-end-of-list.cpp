/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        bool reach = false;
        //sum is the total number in list, count is current idx
        int count = 0, sum = 0;

        function<void(ListNode *)> search = [&](ListNode *cur) {
            sum++;
            //if reach the end
            if (!cur->next)
            {
                reach = true;
                count = 1;
                return;
            }
            search(cur->next);
            //if n = sum, no need to delete anything
            if (n == sum)
                return;
            count++;
            //if count reach n+1, we delete n by link n+1 to n-1
            //test if n-1 exists
            if (count == n + 1)
                cur->next = cur->next->next ? cur->next->next : NULL;
            return;
        };

        search(head);
        if (n == sum)
            return head->next ? head->next : NULL;
        return head;
    }
};
// @lc code=end
