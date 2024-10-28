/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
class Solution {
public:
    bool ismagic(vector<vector<int>> mat, int i, int j)
    {
        //check num value
        vector<bool> tbl(10,false);
        for(int k = i-1; k <= i+1;k++)
        {
            for(int l = j-1; l <= j+1;l++)
            {
                if(mat[k][l] == 0 || mat[k][l] > 9 || tbl[mat[k][l]]) return false;
                tbl[mat[k][l]] = true;
            }
        }
        int sum = mat[i-1][j-1] + mat[i][j-1] + mat[i+1][j-1];

        //check col
        for(int k = 0; k < 2; k++)
        {
            if(sum != mat[i-1][k+j] + mat[i][k+j] + mat[i+1][k+j]) return false;
        }
        
        //check row
        for(int k = -1; k < 2; k++)
        {
            if(sum != mat[k+i][j-1] + mat[k+i][j] + mat[k+i][j+1]) return false;
        }

        //check diagonal
        if(sum != mat[i-1][j-1] + mat[i][j] + mat[i+1][j+1]) return false;
        if(sum != mat[i-1][j+1] + mat[i][j] + mat[i+1][j-1]) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;

        for(int i = 1; i < m - 1; i++)
        {
            for(int j = 1; j < n - 1; j++)
            {
                if(ismagic(grid,i,j)) res++;
            }
        }

        return res;
    }
};
// @lc code=end
/*
[[4,3,8,4],[9,5,1,9],[2,7,6,2]]\n
[[4,3,8,4,5,6,7,8,9],[9,5,1,9,5,6,7,8,9],[2,7,6,2,5,6,7,8,9],[2,7,6,2,5,6,7,8,9]]\n
[[5,5,5],[5,5,5],[5,5,5]]\n
[[8]]\n
*/
