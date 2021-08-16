/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
   public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size(), i = 0, j = 0;
        while (i < len1 || j < len2) {
            int num1 = 0, num2 = 0;
            while (i < len1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < len2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};
// @lc code=end
