/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        int last = 0;
        ListNode *fast = head, *slow = new ListNode(0), *ans = slow;
        while (fast != NULL)
        {
            if (!fast->next || fast->val != fast->next->val)
            {
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            }
            else
            {
                last = fast->val;
                while (fast && fast->val == last)
                    fast = fast->next;
            }
        }
        slow->next = NULL;
        return ans->next;
    }
};
