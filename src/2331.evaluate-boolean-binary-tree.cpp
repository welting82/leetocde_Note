/*
 * @lc app=leetcode id=2331 lang=cpp
 *
 * [2331] Evaluate Boolean Binary Tree
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
    bool evaluateTree(TreeNode* root) {
        if(root->val == 0) return false;
        else if(root->val == 1) return true;
        if(root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
        else if(root->val == 3)
            return evaluateTree(root->left) && evaluateTree(root->right);
        else return false;
    }
};
// @lc code=end

