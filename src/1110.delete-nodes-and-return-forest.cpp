/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode*> res;
    void dfs(TreeNode* &root, vector<int>& del)
    {
        if(!root) return;
        dfs(root->left,del);
        dfs(root->right,del);
        if(find(del.begin(),del.end(),root->val) != del.end())
        {
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            root = NULL;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        dfs(root,del);
        if(root) res.push_back(root);
        return res;
    }
};
// @lc code=end
/*
[1,2,3,4,5,6,7]\n
[2,4]\n
*/
