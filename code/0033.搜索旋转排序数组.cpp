/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        int left = 0, right = n - 1;
        while (left <= right) {  //二分搜索
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                //左半边有序
                if (nums[0] <= target && nums[mid] > target)  //在左半边
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {  //否则右半边有序
                if (nums[mid] < target && nums[n - 1] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
