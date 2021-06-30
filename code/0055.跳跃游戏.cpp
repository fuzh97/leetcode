/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int k = 0;
        for (int i = 0; i < size; i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
            if (k >= size) return true;  //已经可以到达，不需要继续遍历
        }
        return true;
    }
};
// @lc code=end
