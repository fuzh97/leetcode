/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp1, temp2;
        queue<TreeNode*> q;
        if (root == NULL) return ans;
        q.push(root);
        temp1.push_back(root->val);
        ans.push_back(temp1);
        while (!q.empty()) {
            int length = temp1.size();
            while (length--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left != NULL) {
                    q.push(t->left);
                    temp2.push_back(t->left->val);
                }
                if (t->right != NULL) {
                    q.push(t->right);
                    temp2.push_back(t->right->val);
                }
            }
            if (temp2.size() == 0) break;
            temp1.clear();
            temp1 = temp2;
            ans.push_back(temp1);
            temp2.clear();
        }
        return ans;
    }
};
// @lc code=end
