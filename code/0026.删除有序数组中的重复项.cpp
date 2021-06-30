/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 1) return len;
        int slow = 1, fast = 1;
        while (fast < len) {
            if (nums[fast] != nums[slow - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end
