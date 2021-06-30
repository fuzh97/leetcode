/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
/*hashmap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        int ans;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (mp.find(nums[i]) != mp.end())
                mp[nums[i]]++;
            else
                mp[nums[i]] = 1;
        }
        for (map<int, int>::iterator it = mp.begin(); it != mp.end();
            it++) {
            if (it->second == 1) ans = it->first;
        }
        return ans;
    }
};
*/
//位运算
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
// @lc code=end
