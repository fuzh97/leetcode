/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
/*
dfs
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root) {
        if (root) {
            swap(root->left, root->right);
            dfs(root->left);
            dfs(root->right);
        }
    }
};
*/
// bfs
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp != NULL) {
                swap(temp->left, temp->right);
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return root;
    }
};

// @lc code=end
