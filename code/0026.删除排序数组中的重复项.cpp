/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int i = 0, j = 1;
        while (j < len) {
            if (nums[j] != nums[i]) nums[++i] = nums[j];
            j++;
        }
        return i + 1;
    }
};
// @lc code=end
