/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>> &grid, int r, int c) {
        if(r < 0 || c < 0 ||
        r >= grid.size() || c >= grid[0].size() ||
        grid[r][c] == '0') return;

       grid[r][c] = '0';
       
       dfs(grid,r+1,c);
       dfs(grid,r-1,c);
       dfs(grid,r,c+1);
       dfs(grid,r,c-1);
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1') res++,dfs(grid, i, j);
            }
        }
        return res;
    }
};
// @lc code=end
/*
[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
*/
