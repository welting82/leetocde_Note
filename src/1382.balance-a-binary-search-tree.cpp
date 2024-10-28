/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    vector<TreeNode*> vec;
    void dfs(TreeNode* root) {
        if(!root) return;
        if(root->left) dfs(root->left);
        vec.push_back(root);
        if(root->right) dfs(root->right);
        return;
    }
    
    TreeNode* solve(int l,int h) {
        if(l>h) return NULL;
        int m=(l+h)/2;
        vec[m]->left=solve(l,m-1);
        vec[m]->right=solve(m+1,h);
        return vec[m];
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return solve(0,vec.size()-1);
    }
};
// @lc code=end
/*
[1,null,2,null,3,null,4]\n
[2,1,3]\n
*/
