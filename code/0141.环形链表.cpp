/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode* head) {
        if (head == NULL) return false;
        ListNode *p1{head}, *p2{head};
        while (p1 != NULL && p2 != NULL && p1->next != NULL) {
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1 == p2) return true;
        }
        return false;
    }
};
// @lc code=end
