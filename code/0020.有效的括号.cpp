/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> st;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {  //左括号入栈
                st.push(s[i]);
            } else {  //右括号出栈
                if (st.empty()) return false;
                char temp = st.top();
                if (s[i] == ')' && temp == '(')
                    st.pop();
                else if (s[i] == ']' && temp == '[')
                    st.pop();
                else if (s[i] == '}' && temp == '{')
                    st.pop();
                else
                    break;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end
