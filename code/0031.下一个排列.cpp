/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;  //找见第一个升序的i
        if (i >= 0) {
            int j = len - 1;
            while (j >= 0 && nums[j] <= nums[i]) j--;  //找见第一个大于nums[i]的元素
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end
