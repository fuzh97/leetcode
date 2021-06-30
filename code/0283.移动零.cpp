/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i = 0, j = 0;
        for (; i < size; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
// @lc code=end
