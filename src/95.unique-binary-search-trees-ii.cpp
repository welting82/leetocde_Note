/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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

    vector<TreeNode*> dfs(int str, int end)
    {
        vector<TreeNode*> res;
        if(str > end) res.push_back(NULL);

        for (int i = str; i <= end; i++)
        {
            vector<TreeNode*> left = dfs(str, i - 1);
            vector<TreeNode*> right = dfs(i + 1, end);
            for(auto l:left)
            {
                for(auto r:right) res.push_back(new TreeNode(i,l,r));
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
};
// @lc code=end

