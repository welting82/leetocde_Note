/*
 * @lc app=leetcode id=2257 lang=cpp
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> tbl;
    void helper(int m, int n, int i, int j)
    {
        for(int idx = i + 1; idx < m; idx++)
        {
            if(tbl[idx][j] == -1 || tbl[idx][j] == -2) break;
            tbl[idx][j] = 0;
        }
        for(int idx = i - 1; idx > -1; idx--)
        {
            if(tbl[idx][j] == -1 || tbl[idx][j] == -2) break;
            tbl[idx][j] = 0;
        }
        for(int idx = j + 1; idx < n; idx++)
        {
            if(tbl[i][idx] == -1 || tbl[i][idx] == -2) break;
            tbl[i][idx] = 0;
        }
        for(int idx = j - 1; idx > -1; idx--)
        {
            if(tbl[i][idx] == -1 || tbl[i][idx] == -2) break;
            tbl[i][idx] = 0;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        tbl.resize(m, vector<int> (n,1));
        int res = 0;

        for(auto& wall:walls) tbl[wall[0]][wall[1]] = -1;
        for(auto& guard:guards) tbl[guard[0]][guard[1]] = -2;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(tbl[i][j] == -2) helper(m, n, i, j);
            }
        }

        for(auto vec:tbl)
        {
            for(auto i:vec)
            {
                if(i == 1) res += i;
            }
        }
        return res;
    }
};
// @lc code=end
/*
4\n
6\n
[[0,0],[1,1],[2,3]]\n
[[0,1],[2,2],[1,4]]\n
3\n
3\n
[[1,1]]\n
[[0,1],[1,0],[2,1],[1,2]]\n
6\n
10\n
[[0,6],[2,2],[2,5],[1,2],[4,9],[2,9],[5,6],[4,6]]\n
[[1,5]]\n
*/
