/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int dfs(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        sum -= root->val;
        if (sum == 0)
            return 1 + dfs(root->left, sum) + dfs(root->right, sum);
        else
            return dfs(root->left, sum) + dfs(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
// @lc code=end
