/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string intToRoman(int num) {
        vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> reps{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                ans += reps[i];
                num -= values[i];
            }
        }
        return ans;
    }
};
// @lc code=end
