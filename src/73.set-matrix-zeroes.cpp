/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>>& mat, int i, int j)
    {
        if(vis[i][j]) return;
        vis[i][j] = true;
        if(!mat[i][j])
        {
            for(int ii = 0; ii < mat.size(); ii++) dfs(mat, ii, j);
            for(int jj = 0; jj < mat[0].size(); jj++) dfs(mat, i, jj);
        }
        mat[i][j] = 0;
        return;
    }

    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vis.resize(m,vector<bool> (n,false));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0 && !vis[i][j]) dfs(mat, i, j);
            }
        }
        return;
    }
};
// @lc code=end
/*
[[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
[[1]]\n
[[0]]\n
*/
