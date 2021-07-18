/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if (nums.size() == 0) {
            return ans;
        }
        int cand1 = 0, cand2 = 0, count1 = 0, count2 = 0, len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] == cand1) {
                count1++;
            } else if (nums[i] == cand2) {
                count2++;
            } else if (count1 > 0 && count2 > 0) {
                count1--;
                count2--;
            } else if (count1 == 0) {
                cand1 = nums[i];
                count1++;
            } else {
                cand2 = nums[i];
                count2++;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == cand1) {
                count1++;
            } else if (nums[i] == cand2) {
                count2++;
            }
        }
        if (count1 > len / 3) ans.push_back(cand1);
        if (count2 > len / 3) ans.push_back(cand2);
        return ans;
    }
};
// @lc code=end
