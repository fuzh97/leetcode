/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1 + s2 > s2 + s1;  //返回组合起来更大的顺序
        });
        if (nums[0] == 0) {
            return "0";
        }
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};
// @lc code=end
