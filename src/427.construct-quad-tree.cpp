/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    void helper(vector<vector<int>>& grid, vector<int> idxs, Node* root)
    {
        int n = idxs[3] - idxs[1], len = n / 2, sum;
        vector<pair<int,int>> list = {{idxs[0], idxs[1]}, {idxs[0], idxs[1] + len},
                        {idxs[0] + len, idxs[1]}, {idxs[0] + len, idxs[1] + len}};
        root->topLeft = new Node(), root->topRight = new Node();
        root->bottomLeft = new Node(), root->bottomRight = new Node();
        vector<Node*> vec = {root->topLeft, root->topRight, 
                            root->bottomLeft, root->bottomRight};

        for(int idx = 0; idx < list.size(); idx++)
        {
            sum = 0;
            for(int i = list[idx].first; i < list[idx].first + len; i++)
            {
                for(int j = list[idx].second; j < list[idx].second + len; j++) sum += grid[i][j];
            }

            if(sum == 0 || sum == len * len)
            {
                vec[idx]->isLeaf = true;
                vec[idx]->val = (sum)? 1: 0;
            }
            else
            {
                helper(grid, {list[idx].first, list[idx].second,
                        list[idx].first + len, list[idx].second + len}, vec[idx]);
            }
        }
        return;
    }

    Node* construct(vector<vector<int>>& grid) {
        Node* res = new Node();
        int n = grid.size();
        helper(grid, {0, 0, n, n}, res);
        if(res->topLeft->isLeaf && res->topRight->isLeaf && res->bottomLeft->isLeaf && res->bottomRight->isLeaf &&
            res->topLeft->val == grid[0][0] && res->topRight->val == grid[0][0] &&
            res->bottomLeft->val == grid[0][0] && res->bottomRight->val == grid[0][0])
        {
            return new Node(grid[0][0], true);
        }
        return res;
    }
};
// @lc code=end
/*
[[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]\n
[[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1]]\n
*/

