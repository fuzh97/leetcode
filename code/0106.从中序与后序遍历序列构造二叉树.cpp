/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int postL, int postR) {
        if (postL > postR) return nullptr;
        int temp = postorder[postR], k;       //根节点为后续遍历的最后一个节点
        TreeNode* node = new TreeNode(temp);  //建立根节点
        for (k = inL; k <= inR; k++) {
            if (inorder[k] == temp) break;  //k为根节点在中序遍历中的位置，以此分左右子树
        }
        int num = k - inL;  //左子树的个数
        node->left = build(inorder, postorder, inL, k - 1, postL, postL + num - 1);
        node->right = build(inorder, postorder, k + 1, inR, postL + num, postR - 1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inL = 0, inR = inorder.size() - 1, postL = 0, postR = postorder.size() - 1;
        return build(inorder, postorder, inL, inR, postL, postR);
    }
};
// @lc code=end
