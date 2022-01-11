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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree1(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        std::queue<TreeNode*> treeNodeQueue;
        treeNodeQueue.push(root);
        while (!treeNodeQueue.empty())
        {
            TreeNode * cur = treeNodeQueue.front();
            treeNodeQueue.pop();
            TreeNode *left = cur->left;
            TreeNode *right = cur->right;
            cur->left = right;
            cur->right = left;
            if(left) treeNodeQueue.push(left);
            if(right) treeNodeQueue.push(right);         
        }
        return root;
    }
};
// @lc code=end

