/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
int preInd=0;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return createTree(preorder,inorder,0,inorder.size() - 1);
    }
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,int start, int end){
        if(start > end){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[preInd++]);
        int pos;
        for(int i=start;i<=end;i++){
            if(inorder[i]==node->val){
                pos=i;
                break;
            }
        }
        node->left =createTree(preorder, inorder,start,pos-1);
        node->right =createTree(preorder, inorder, pos+1,end);
        return node;
    }
};
// @lc code=end
/*
[3,9,20,15,7]\n
[9,3,15,20,7]\n
[1,2,4,5,3,6,7]\n
[4,2,5,1,6,3,7]\n
[-1]\n
[-1]\n
[1,2,5,3,7]\n
[2,5,1,3,7]\n
[1,3,7]\n
[1,3,7]\n
[1,3,7]\n
[7,3,1]\n
*/
