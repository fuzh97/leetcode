/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if (preL > preR) return NULL;         //先序序列长度小于等于0时，直接返回
        int temp = preorder[preL], k;         //先序遍历第一个节点为头节点
        TreeNode* node = new TreeNode(temp);  //建立新节点
        for (k = inL; k <= inR; k++) {
            if (inorder[k] == temp) break;
        }
        int num = k - inL;  //左子树元素的个数
        node->left = build(preorder, inorder, preL + 1, preL + num, inL, k - 1);
        node->right = build(preorder, inorder, preL + num + 1, preR, k + 1, inR);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preL = 0, preR = preorder.size() - 1, inL = 0, inR = inorder.size() - 1;
        return build(preorder, inorder, preL, preR, inL, inR);
    }
};
/*
3 9 20 15 7
9 3 15 20 7
*/
// @lc code=end
