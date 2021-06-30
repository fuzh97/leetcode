/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *p = head, *q = p->next;
        p->next = NULL;
        while (q) {
            ListNode* s = q->next;
            q->next = p;
            p = q;
            q = s;
        }
        return p;
    }
};
// @lc code=end
