/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth, bool isLeft = true) {
        if(depth == 1)
        {
            TreeNode *left = isLeft? root : NULL, *right = isLeft? NULL : root;
            return new TreeNode(val, left, right);
        }
        if(root)
        {
            root->left = addOneRow(root->left, val, depth-1);
            root->right = addOneRow(root->right, val, depth-1, false);
        }
        return root;
    }
};
// @lc code=end
/*
[4,2,6,3,1,5]\n
1\n
2\n
[4,2,6,3,1,5]\n
10\n
3\n
[0]\n
10\n
1\n
*/
