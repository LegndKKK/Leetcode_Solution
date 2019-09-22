/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;
        int count = 0;
        ListNode *cur = head;
        while (cur->next)
        {
            cur = cur->next;
            count++;
        }
        count++;
        int mov = k % count;
        if (!mov)
            return head;
        count -= mov;
        cur->next = head;
        cur = head;
        while (count > 1)
        {
            cur = cur->next;
            count--;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};
