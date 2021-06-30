/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        int left = 1, right = size - 1;
        while (left < right) {
            int mid = (right + left) / 2;
            int cnt = 0;
            for (int num : nums) {
                if (num <= mid) cnt++;
            }
            if (cnt > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
