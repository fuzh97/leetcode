/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        else if (size == 1)
            return nums[0];
        int maxP = nums[0], minP = nums[0], ans = nums[0];
        for (int i = 1; i < size; i++) {
            int temp = maxP;
            maxP = max(max(maxP * nums[i], nums[i]), minP * nums[i]);
            minP = min(min(temp * nums[i], nums[i]), minP * nums[i]);
            ans = max(maxP, ans);
        }
        return ans;
    }
};
// @lc code=end
