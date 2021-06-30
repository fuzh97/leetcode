/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        /*
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
        */
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
// @lc code=end
