/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int up = 0;
        ListNode *head = l1, *cur = l1;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        while (l1 && l2)
        {
            l1->val = l1->val + l2->val + up;
            up = l1->val / 10;
            l1->val %= 10;
            cur = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            l1->val += up;
            up = l1->val / 10;
            l1->val %= 10;
            cur = l1;
            l1 = l1->next;
        }
        while (l2)
        {
            ListNode *temp = new ListNode(l2->val + up);
            up = temp->val / 10;
            temp->val %= 10;
            l2 = l2->next;
            cur->next = temp;
            cur = cur->next;
        }
        while (up > 0)
        {
            ListNode *temp = new ListNode(up);
            up = temp->val / 10;
            temp->val %= 10;
            cur->next = temp;
            cur = cur->next;
        }
        return head;
    }
};
