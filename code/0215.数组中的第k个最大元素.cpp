/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;
        for (int n : nums) {
            if (q.size() >= k && q.top() >= n) continue;
            q.push(n);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }
};
// @lc code=end
