/*
 * @lc app=leetcode id=2471 lang=cpp
 *
 * [2471] Minimum Number of Operations to Sort a Binary Tree by Level
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
    int helper(vector<int> vec)
    {
        unordered_map<int,int> umap;
        vector<int> arr = vec;
        int cnt = 0, init;
        for(int i = 0; i < vec.size(); i++) umap[vec[i]] = i;
        sort(vec.begin(), vec.end());
        for(int i = 0;  i < vec.size(); i++)
        {
            if(vec[i] != arr[i])
            {
                init = arr[i];
                swap(arr[i], arr[umap[vec[i]]]);
                umap[init] = umap[vec[i]];
                umap[vec[i]] = i;
                cnt++;
            }
        }
        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        int res = 0, cnt, qsize;
        queue<TreeNode*> q;
        vector<int> vec;

        q.push(root);
        while(!q.empty())
        {
            qsize = q.size();
            cnt = 0;
            for(int i = 0; i < qsize; i++)
            {
                vec.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res += helper(vec);
            vec.clear();
        }
        return res;
    }
};
// @lc code=end
/*
[1,3,2,7,6,5,4]\n
[1,2,3,4,5,6]\n
[49,45,1,20,46,15,39,27,null,null,null,25]\n
*/
