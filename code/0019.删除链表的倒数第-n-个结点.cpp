/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        for (int i = 0; i < n; i++) {
            q = q->next;
        }
        if (q != NULL) {  //如果不是删除第一个节点
            while (q->next != NULL) {
                q = q->next;
                p = p->next;
            }
            p->next = p->next->next;
        } else {  //删除第一个节点
            head = head->next;
        }
        return head;
    }
};
// @lc code=end
