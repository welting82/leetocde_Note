/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    vector<vector<bool>> vis{100, vector<bool>(100,false)};
    bool isOutbound(vector<vector<int>> grid, int r, int c) {
        return (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())?true:false;
    }

    void dfs(vector<vector<int>> grid, int r, int c) {
        if(isOutbound(grid, r, c) || vis[r][c] || grid[r][c] == 0) return;
        vis[r][c] = true;
        
        if(isOutbound(grid, r-1, c) || grid[r-1][c] == 0) res++;
        if(isOutbound(grid, r+1, c) || grid[r+1][c] == 0) res++;
        if(isOutbound(grid, r, c+1) || grid[r][c+1] == 0) res++;
        if(isOutbound(grid, r, c-1) || grid[r][c-1] == 0) res++;
        
        dfs(grid, r+1,c);
        dfs(grid, r-1,c);
        dfs(grid, r,c+1);
        dfs(grid, r,c-1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int  j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1) 
                {
                    dfs(grid, i, j);
                    break;
                }
            }
            
        }
        return res;
    }
};
// @lc code=end
/*
[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]\n
[[1]]\n
[[1,0]]\n
*/
