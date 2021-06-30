/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            int low = i + 1, high = len - 1;
            if (nums[i] > 0) {
                break;  //如果当前的nums[i]已经大于0，则一定不会有结果，跳出循环
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  //去重
            };
            while (low < high) {
                int temp = nums[low] + nums[high] + nums[i];
                if (temp < 0) {
                    low++;
                } else if (temp == 0) {
                    vector<int> vtemp{nums[i], nums[low], nums[high]};
                    ans.push_back(vtemp);
                    vtemp.clear();
                    //去重
                    while (low < high && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    while (low < high && nums[high] == nums[high - 1]) {
                        high--;
                    }

                    low++, high--;
                } else {
                    high--;
                }
            }
        }
        return ans;
    };
};
/*
6
-1 0 1 2 -1 -4
*/
// @lc code=end
