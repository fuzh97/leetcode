/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1, ans = 0;
        while (low < high) {
            int temp = min(height[low], height[high]) * (high - low);
            if (temp > ans) ans = temp;
            if (height[low] <= height[high])
                low++;
            else
                high--;
        }
        return ans;
    }
};
// @lc code=end
