/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
/*hashmap
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int size = nums.size(), ans;
        for (int i = 0; i < size; i++) {
            if (mp.find(nums[i]) != mp.end())
                mp[nums[i]]++;
            else
                mp[nums[i]] = 1;
        }
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end();
             it++) {
            if (it->second > size / 2) {
                ans = it->first;
                break;
            }
        }
        return ans;
    }
};
*/
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int ans = nums[0], count = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] == ans)
                count++;
            else
                count--;
            if (count < 0) {
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};
// @lc code=end
