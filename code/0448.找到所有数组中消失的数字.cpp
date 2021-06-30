/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            int temp = abs(nums[i]) - 1;
            if (nums[temp] > 0)
                nums[temp] *= -1;
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
// @lc code=end
