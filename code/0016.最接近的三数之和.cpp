/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = nums[0] + nums[1] + nums[2];  //取前三个相加，做临时最优解
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            int start = i + 1, end = len - 1;
            while (start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if (abs(target - sum) < abs(target - best)) best = sum;
                if (sum > target)
                    end--;
                else if (sum < target)
                    start++;
                else
                    return best;
            }
        }
        return best;
    }
};
// @lc code=end
