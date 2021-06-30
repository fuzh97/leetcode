/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/*
class Solution {
   public:
    void flatten(TreeNode* root) {
        while (root != NULL) {
            if (root->left == NULL) {
                root = root->right;
            } else {
                TreeNode* temp = root->left;
                while (temp->right != NULL) temp = temp->right;
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};
*/
class Solution {
   public:
    vector<int> ans;
    void flatten(TreeNode* root) {
        preorder(root);
        TreeNode* p = root;
        root->left = root->right = NULL;
        root->val = ans[0];
        int length = ans.size();
        for (int i = 1; i < length - 1; i++) {
            TreeNode* q = new TreeNode(ans[i]);
            q = p->right;
            p = q;
        }
    }
    void preorder(TreeNode* root) {
        if (root == NULL) return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};
// @lc code=end
