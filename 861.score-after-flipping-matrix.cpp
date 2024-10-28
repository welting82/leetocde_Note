/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int res = 0, count, sum = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++)
        {
            if(!(grid[i][0] & 1))
            {
                for(int j = 0; j < m; j++) grid[i][j] = !grid[i][j];
            }
        }

        for(int i = 1; i < m; i++)
        {
            count = 0;
            for(int j = 0; j < n; j++)
            {
                if(grid[j][i] & 1) count++;
            }
            if(count*2 < n)
            {
                for(int j = 0; j < n; j++) grid[j][i] = !grid[j][i];
            }
            
        }

        for(auto i:grid)
        {
            for(int j:i)
            {
                sum = (sum*2 + j);
            }
            res += sum;
            sum = 0;
        }
        return res;
    }
};
// @lc code=end
/*
[[0,0,1,1],[1,0,1,0],[1,1,0,0]]\n
[[0]]\n
*/
