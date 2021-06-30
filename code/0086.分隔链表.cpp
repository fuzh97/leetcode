/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *p = new ListNode(0);
        ListNode *q = new ListNode(0);
        ListNode *head1 = p, *head2 = q;
        while (head != nullptr) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            } else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        q->next = nullptr;
        p->next = head2->next;
        return head1->next;
    }
};
// @lc code=end
