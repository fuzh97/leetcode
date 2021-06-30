/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 4) return res;
        for (int i = 0; i <= len - 4; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j <= len - 3; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int start = j + 1, end = len - 1;
                while (start < end) {
                    int temp = nums[i] + nums[j] + nums[start] + nums[end];
                    if (temp > target)
                        end--;
                    else if (temp < target)
                        start++;
                    else {
                        res.push_back({nums[i], nums[j], nums[start], nums[end]});
                        while (start < end && nums[start + 1] == nums[start]) start++;
                        while (start < end && nums[end - 1] == nums[end]) end--;
                        start++;
                        end--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
