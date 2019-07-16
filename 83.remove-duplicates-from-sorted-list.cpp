/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
        ListNode *fast = head, *slow = head;
        int last = head->val;
        while (fast->next)
        {
            fast = fast->next;
            if (fast->val != last)
            {
                slow = slow->next;
                slow->val = fast->val;
                last = fast->val;
            }
        }
        slow->next = NULL;
        return head;
    }
};
