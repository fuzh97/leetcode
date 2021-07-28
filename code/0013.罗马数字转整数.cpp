/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            int temp = mp[s[i]];
            if (i < len - 1 && (mp[s[i]] < mp[s[i + 1]])) {
                ans -= temp;
            } else {
                ans += temp;
            }
        }
        return ans;
    }
};
// @lc code=end
