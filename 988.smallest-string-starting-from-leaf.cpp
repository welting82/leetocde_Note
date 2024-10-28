/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
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
    string res = "~";
    void dfs(TreeNode* root, string tmp) {
        tmp.insert(tmp.begin(),char(root->val + 97));
        if(!root->left && !root->right) res = min(res, tmp);
        if(root->left) dfs(root->left, tmp);
        if(root->right) dfs(root->right, tmp);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return res;
    }
};
// @lc code=end
/*
[1,1,3,3,4]\n
[0,1,2,3,4,3,4]\n
[25,1,3,1,3,0,2]\n
[2,2,1,null,1,0,null,0]\n
*/
