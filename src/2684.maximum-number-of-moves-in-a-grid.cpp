/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 */

// @lc code=start
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int res = 0, ori_val, n = grid.size(), m = grid[0].size();
        vector<vector<int>> tbl(n,vector<int> (m,0));

        for(int j = 1; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                if(tbl[i][j-1] != -1 || tbl[max(0,i-1)][j-1] != -1 || tbl[min(n-1,i+1)][j-1] != -1)
                {
                    ori_val = tbl[i][j];
                    if(grid[i][j] > grid[max(0,i-1)][j-1])
                    {
                        tbl[i][j] = max(tbl[i][j], tbl[max(0,i-1)][j-1] + 1);
                    }
                    if(grid[i][j] > grid[i][j-1])
                    {
                        tbl[i][j] = max(tbl[i][j], tbl[i][j-1] + 1);
                    }
                    if(grid[i][j] > grid[min(n-1,i+1)][j-1])
                    {
                        tbl[i][j] = max(tbl[i][j], tbl[min(n-1,i+1)][j-1] + 1);
                    }
                    if(ori_val == tbl[i][j])
                    {
                        res = max(max(max(res,tbl[i][j-1]),tbl[max(0,i-1)][j-1]),tbl[min(n-1,i+1)][j-1]);
                        tbl[i][j] = -1;
                    }
                }
                else tbl[i][j] = -1;
                if(j == m-1) res = max(res,tbl[i][j]);
            }
        }
        
        return res;
    }
};
// @lc code=end
/*
[[3,2,4],[2,1,9],[1,1,7]]\n
[[2,4,3,5],[5,4,9,3],[3,4,2,8],[10,9,13,11]]\n
[[187,167,209,251,152,236,263,128,135],[267,249,251,285,73,204,70,207,74],[189,159,235,66,84,89,153,111,189],[120,81,210,7,2,231,92,128,218],[193,131,244,293,284,175,226,205,245]]\n
[[65,200,263,220,91,183,2,187,175,61,225,120,39],[111,242,294,31,241,90,145,25,262,214,145,71,294],[152,25,240,69,279,238,222,9,137,277,8,143,143],[189,31,86,250,20,63,188,209,75,22,127,272,110],[122,94,298,25,90,169,68,3,208,274,202,135,275],[205,20,171,90,70,272,280,138,142,151,80,122,130],[284,272,271,269,265,134,185,243,247,50,283,20,232],[266,236,265,234,249,62,98,130,122,226,285,168,204],[231,24,256,101,142,28,268,82,111,63,115,13,144],[277,277,31,144,49,132,28,138,133,29,286,45,93],[163,96,25,9,3,159,148,59,25,81,233,127,12],[127,38,31,209,300,256,15,43,74,64,73,141,200]]\n
*/