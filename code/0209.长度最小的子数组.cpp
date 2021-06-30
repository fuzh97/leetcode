/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
   public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX, left = 0, right = 0, sum = 0;
        int size = nums.size();
        while (right < size) {
            if (sum + nums[right] < s) {
                sum += nums[right];
                right++;
            } else {
                ans = min(right - left + 1, ans);
                sum -= nums[left];
                left++;
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};
// @lc code=end
