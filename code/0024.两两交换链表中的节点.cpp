/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
/*
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummyHead = new ListNode(0);  //创建虚拟节点
    dummyHead->next = head;
    ListNode* prev = dummyHead;
    while (prev->next != nullptr && prev->next->next != nullptr) {
      ListNode* p = prev->next;
      ListNode* q = prev->next->next;
      p->next = p->next->next;
      q->next = p;
      prev->next = q;
      prev = p;
    }
    return dummyHead->next;
  }
};
*/
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
  }
};
// @lc code=end
