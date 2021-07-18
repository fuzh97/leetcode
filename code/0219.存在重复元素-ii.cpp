/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0 || nums.size() == 1) {
            return false;
        }
        unordered_map<int, int> mp;  //<元素，上一次出现的下表>
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                //存在已经出现过的元素，判断距离
                if ((i - mp[nums[i]]) <= k) {
                    return true;
                } else {
                    mp[nums[i]] = i;  //更新位置
                }
            } else {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end
