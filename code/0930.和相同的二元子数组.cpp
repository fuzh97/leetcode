/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int len = nums.size(), count = 0, pre = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < len; i++) {
            pre += nums[i];
            if (mp.find(pre - goal) != mp.end()) {
                count += mp[pre - goal];
            }
            mp[pre]++;
        }
        return count;
    }
};
// @lc code=end
