/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
   public:
    string repeat(const string& str, int times) {
        //将字符串str重复times次
        string res = "";
        for (int i = 0; i < times; i++) {
            res += str;
        }
        return res;
    }
    string decodeString(string s) {
        int repeatTimes = 0;
        string res = "";
        stack<pair<int, string>> vecStack;
        for (char i : s) {
            if (i >= '0' && i <= '9')
                repeatTimes = (repeatTimes * 10) + (i - '0');
            else if (i == '[') {
                vecStack.push(make_pair(repeatTimes, res));
                res = "";
                repeatTimes = 0;
            } else if (i == ']') {
                pair<int, string> temp = vecStack.top();
                vecStack.pop();
                res = temp.second + (temp.first == 0 ? "" : repeat(res, temp.first));
            } else
                res += i;
        }
        return res;
    }
};
// @lc code=end
