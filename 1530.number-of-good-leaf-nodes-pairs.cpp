/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
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
    vector<string> tbl;
    void dfs(TreeNode* root, string s)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            tbl.push_back(s);
            return;
        }
        s.push_back('L'),dfs(root->left,s),s.pop_back();
        s.push_back('R'),dfs(root->right,s),s.pop_back();
        return;
    }

    int countPairs(TreeNode* root, int dist) {
        string s;
        int idx,res = 0;
        dfs(root,s);

        for(int i = 0; i < tbl.size(); i++)
        {
            for(int j = i + 1; j < tbl.size(); j++)
            {
                idx = 0;
                while (tbl[i][idx] == tbl[j][idx]) idx++;
                if(((tbl[j].size() - idx) + (tbl[i].size() - idx)) <= dist) res++;
            }
        }
        return res;
    }
};
// @lc code=end
/*
[1,2,3,4,null,6,7]\n
3\n
[1,2,3,4,5,6,7]\n
3\n
*/