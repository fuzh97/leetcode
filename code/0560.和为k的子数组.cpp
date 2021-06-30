/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size(), count = 0, pre = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < len; i++) {
            pre += nums[i];
            if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }
};
// @lc code=end
