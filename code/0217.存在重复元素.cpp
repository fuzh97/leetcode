/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return false;
        }
        unordered_map<int, int> mp;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                return true;
            } else {
                mp[nums[i]] = 1;
            }
        }
        return false;
    }
};
// @lc code=end
