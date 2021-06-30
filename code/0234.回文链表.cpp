/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
/*
辅助数组
class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        ListNode* p = head;
        while (p) {
            temp.push_back(p->val);
            p = p->next;
        }
        int size = temp.size();
        for (int i = 0; i < size / 2; i++) {
            if (temp[i] != temp[size - i - 1]) return false;
        }
        return true;
    }
};
*/
//反转链表
class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        ListNode *halfNode = p, *nextNode = p->next;
        while (nextNode) {
            ListNode *s = nextNode->next;
            nextNode->next = halfNode;
            halfNode = nextNode;
            nextNode = s;
        }
        p->next = NULL, p = head, q = halfNode;
        while (p && q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
// @lc code=end
