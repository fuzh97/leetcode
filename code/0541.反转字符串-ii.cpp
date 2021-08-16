/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
   public:
    void reverse(string& s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            //1.有2k个字符，反转前k个
            //2.有[k,2k)个字符，反转前k个
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
                continue;
            }
            //3.剩余[0,k)个字符，全部反转
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};
// @lc code=end
