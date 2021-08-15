/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
   public:
    unordered_map<char, int> oper_pri = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'%', 2},
        {'^', 3}};
    stack<char> ops;
    stack<long long> nums;

    void cal() {
        long long b = nums.top();
        nums.pop();
        long long a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        long long res;
        switch (op) {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = a / b;
                break;
            case '%':
                res = a % b;
                break;
            case '^':
                res = pow(a, b);
                break;
        }
        nums.push(res);
    }

    int calculate(string s) {
        nums.push(0);
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '(') {
                ops.push(s[i]);
                if (s[i + 1] == '-') {
                    i++;
                    nums.push(0);
                    ops.push(s[i + 1]);
                }
            } else if (s[i] == ')') {
                while (ops.top() != '(') {
                    cal();
                }
                ops.pop();
            } else if (isdigit(s[i])) {
                int temp = s[i] - '0';
                while (i < len - 1 && isdigit(s[i + 1])) {
                    temp = temp * 10 + (s[i + 1] - '0');
                    i++;
                }
                nums.push(temp);
            } else {
                while (!ops.empty() && ops.top() != '(' && oper_pri[ops.top()] >= oper_pri[s[i]]) {
                    //栈内运算符优先级大于当前运算符优先级，先计算
                    cal();
                }
                ops.push(s[i]);
            }
        }
        while (!ops.empty() && ops.top() != '(') {
            //处理栈中剩余字符
            cal();
        }
        return nums.top();
    }
};
// @lc code=end
