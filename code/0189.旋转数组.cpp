/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;  //防止k超过数组长度
        if (k == 0) return;
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end
