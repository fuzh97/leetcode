/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int max_length;
    int maxDepth(TreeNode* root) {
        dfs(root, 0);  //从根节点开始遍历
        return max_length;
    }
    void dfs(TreeNode* root, int depth) {
        if (root == NULL) {
            if (depth > max_length) max_length = depth;
            return;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};
// @lc code=end
