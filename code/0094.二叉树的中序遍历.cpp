/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    /*递归
     vector<int> ans;
     vector<int> inorderTraversal(TreeNode* root) {
         if (root != NULL) {
             inorderTraversal(root->left);
             ans.push_back(root->val);
             inorderTraversal(root->right);
         }
         return ans;
     }
     */
    //迭代
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while (temp || !st.empty()) {
            while (temp) {  //如果存在左孩子，则一直向下入栈
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();  //取栈顶并出栈
            st.pop();
            ans.push_back(temp->val);
            temp = temp->right;  //如果存在右孩子，右孩子入栈，继续判断
        }
        return ans;
    }
};
// @lc code=end
