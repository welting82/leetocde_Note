/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
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
    void dfs(TreeNode* l, TreeNode* r, int lvl)
    {
        if(!l) return;
        if(l->left) dfs(l->left, r->right, lvl + 1);
        if(l->right) dfs(l->right, r->left, lvl + 1);
        if(lvl % 2) swap(l->val, r->val);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
};
// @lc code=end
/*
[2,3,5,8,13,21,34,1,2,3,4,5,6,7,8]\n
[7,13,11]\n
[0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]\n
*/
