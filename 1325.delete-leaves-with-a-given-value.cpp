/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
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
    void dfs(TreeNode* &root, int target)
    {
        if(root->left) dfs(root->left,target);
        if(root->right) dfs(root->right,target);
        if(!root->left && !root->right && root->val == target) root = NULL;
        return;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root,target);
        return root;
    }
};
// @lc code=end
/*
[1,2,3,2,null,2,4]\n
2\n
[1,3,3,3,2]\n
3\n
[1,1,1]\n
1\n
*/
