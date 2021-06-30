/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        int countA = 0, countB = 0, x;
        while (p) {
            p = p->next;
            countA++;
        }
        while (q) {
            q = q->next;
            countB++;
        }
        x = countA - countB;
        p = headA, q = headB;
        if (x < 0) {  // B比较长
            x *= -1;
            while (x--) {
                q = q->next;
            }
        } else {  // A比较长
            while (x--) {
                p = p->next;
            }
        }
        while (p || q) {
            if (p == q) return q;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};
// @lc code=end
