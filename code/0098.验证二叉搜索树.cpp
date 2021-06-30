/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    vector<int> ans;
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        inOrder(root);
        int size = ans.size();
        for (int i = 0; i < size - 1; i++) {
            if (ans[i + 1] <= ans[i]) return false;
        }
        return true;
    }
    void inOrder(TreeNode* root) {
        if (root->left) inOrder(root->left);
        ans.push_back(root->val);
        if (root->right) inOrder(root->right);
    }
};
// @lc code=end
