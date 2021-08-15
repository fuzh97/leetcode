/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
   public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> vec1, vec2, res;
        int len = expression.size();
        int flag = 0;  // 0:数字，1：表达式
        for (int i = 0; i < len; i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                flag = 1;
                vec1 = diffWaysToCompute(string(expression, 0, i));
                vec2 = diffWaysToCompute(string(expression, i + 1, len - i - 1));
                for (int v1 : vec1) {
                    for (int v2 : vec2) {
                        if (expression[i] == '+') {
                            res.push_back(v1 + v2);
                        } else if (expression[i] == '-') {
                            res.push_back(v1 - v2);
                        } else if (expression[i] == '*') {
                            res.push_back(v1 * v2);
                        }
                    }
                }
            }
        }
        if (flag == 0) {
            return {stoi(expression)};
        }
        return res;
    }
};
// @lc code=end
