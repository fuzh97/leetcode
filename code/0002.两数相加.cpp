/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        while (l1 || l2 || carry) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            ListNode* newNode = new ListNode(sum % 10);
            node->next = newNode;
            node = newNode;
            carry = sum /= 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head->next;
    }
};
// @lc code=end
