/*
 * @lc app=leetcode id=2196 lang=cpp
 *
 * [2196] Create Binary Tree From Descriptions
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
    TreeNode* createBinaryTree(vector<vector<int>>& descp) {
        unordered_map<int,TreeNode*> umap;
        unordered_set<int> uset;
        int root = descp[0][0], idx = 0;


        for(auto i:descp)
        {
            uset.insert(i[1]);
            if(!umap[i[0]]) umap[i[0]] = new TreeNode(i[0]);
            if(!umap[i[1]]) umap[i[1]] = new TreeNode(i[1]);
            if(i[2]) umap[i[0]]->left = umap[i[1]];
            else umap[i[0]]->right = umap[i[1]];
        }

        for(int i = 0; i < descp.size(); i++)
        {
            if(!uset.count(descp[i][0])) root = descp[i][0];
        }

        return umap[root];
    }
};
// @lc code=end
/*
[[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]\n
[[1,2,1],[2,3,0],[3,4,1]]\n
*/
