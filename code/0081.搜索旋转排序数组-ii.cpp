#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return (nums[0] == target);
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                //数组中有重复元素会出现的特殊情况，缩小区间继续二分
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                //左半边有序
                if (nums[left] <= target && nums[mid] > target) {
                    //在左半边
                    right = mid - 1;
                } else {
                    //在右半边
                    left = mid + 1;
                }
            } else {
                //右半边有序
                if (nums[right] >= target && nums[mid] < target) {
                    //在右半边
                    left = mid + 1;
                } else {
                    //在左半边
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end
