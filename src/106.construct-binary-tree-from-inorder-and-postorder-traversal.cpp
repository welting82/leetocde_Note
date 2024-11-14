/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    int post_idx;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int str, int end) {
        if(str > end) return NULL;
        TreeNode* root = new TreeNode(postorder[post_idx--]);

        int idx = -1;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == root->val)
            {
                idx = i;
                break;
            }
        }
        root->right = helper(inorder, postorder, idx + 1, end);
        root->left = helper(inorder, postorder, str, idx - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = inorder.size()- 1;
        return helper(inorder, postorder, 0, inorder.size()- 1);
    }
};
// @lc code=end
/*
[9,3,15,20,7]\n
[9,15,7,20,3]\n
[1,2,3,4,5]\n
[5,4,3,2,1]\n
[5,4,3,2,1]\n
[1,2,3,4,5]\n
*/
