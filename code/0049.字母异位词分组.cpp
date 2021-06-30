/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int count = 0, size = strs.size();
        string temp;
        unordered_map<string, int> mp;
        for (int i = 0; i < size; i++) {
            string str = strs[i];
            temp = str;
            sort(temp.begin(), temp.end());
            if (mp.find(temp) != mp.end()) {  //已经存在
                ans[mp[temp]].push_back(str);
            } else {                         //不存在
                vector<string> vec(1, str);  //建立新数组
                ans.push_back(vec);
                mp[temp] = count++;  //更新下标
            }
        }
        return ans;
    }
};
// @lc code=end
