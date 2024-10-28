/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
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
    TreeNode* lca(TreeNode* root, int s, int d)
    {
        if(!root) return nullptr;
        if(root->val == s || root->val == d) return root;
        TreeNode* l = lca(root->left, s, d);
        TreeNode* r = lca(root->right, s, d);
        if(l && r) return root;
        return l?l:r;
    }

    bool path(TreeNode* root, int dest, string &p)
    {
        if(!root) return false;
        if(root->val == dest) return true;
        
        p.push_back('L');
        if(path(root->left,dest,p)) return true;
        else p.pop_back();

        p.push_back('R');
        if(path(root->right,dest,p)) return true;
        else p.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int str, int dest) {
        string pl,pr;
        TreeNode* anc = lca(root,str,dest);

        path(anc,str,pl);
        path(anc,dest,pr);
        for(auto &ch:pl) ch = 'U';
        return pl + pr;
    }
};
// @lc code=end

