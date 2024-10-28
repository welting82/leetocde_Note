/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int res = 0;
    void dfs(TreeNode* root, int sum) {
        sum += root->val;
        if(!root->left && !root->right) res += sum;
        if (root->right) dfs(root->right, sum*10);
        if (root->left) dfs(root->left, sum*10);
        return;
    }

    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};
// @lc code=end
/*
[1,2,3]\n
[4,9,0,5,1]\n
*/
