/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
   public:
    int upper_bound(vector<int>& nums, int targets) {
        //找出序列中第一个大于x的位置的元素
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > targets)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    int lower_bound(vector<int>& nums, int targets) {
        //找出序列中第一个大于等于x的位置的元素
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] >= targets)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        if (nums.size() == 1) {
            if (nums[0] == target)
                return {0, 0};
            else
                return {-1, -1};
        }
        int low = lower_bound(nums, target);
        int high = upper_bound(nums, target);
        if (nums[low] != target)
            return {-1, -1};
        else if (nums[high] == target)
            return {low, high};
        else
            return {low, high - 1};
    }
};
// @lc code=end
