/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int ans = 0;
    int dfs(TreeNode* root) {  //返回该节点最深向下有多少节点
        if (root == NULL) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = max(ans, l + r + 1);  //更新最大
        return max(l, r) + 1;       //当前节点的高度。
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        dfs(root);
        return ans - 1;
    }
};
// @lc code=end
