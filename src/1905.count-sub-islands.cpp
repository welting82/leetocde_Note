/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution {
public:
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        queue<pair<int,int>> q;
        pair<int,int> tmp;
        bool con;

        for(int i = 0; i < grid2.size(); i++)
        {
            for(int j = 0; j < grid2[0].size(); j++)
            {
                if(grid2[i][j])
                {
                    q.push({i,j});
                    con = true;
                    while(!q.empty())
                    {
                        tmp = q.front(),q.pop();
                        if(!grid1[tmp.first][tmp.second]) con = false;
                        grid2[tmp.first][tmp.second] = 0;
                        if(tmp.first-1 > -1 && grid2[tmp.first-1][tmp.second]) q.push({tmp.first-1,tmp.second});
                        if(tmp.first+1 < grid2.size() && grid2[tmp.first+1][tmp.second]) q.push({tmp.first+1,tmp.second});
                        if(tmp.second-1 > -1 && grid2[tmp.first][tmp.second-1]) q.push({tmp.first,tmp.second-1});
                        if(tmp.second+1 < grid2[0].size() && grid2[tmp.first][tmp.second+1]) q.push({tmp.first,tmp.second+1});
                    }
                    if(con) res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
/*
[[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]\n
[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]\n

[[1,1,1,1,0,0],[1,1,0,1,0,0],[1,0,0,1,1,1],[1,1,1,0,0,1],[1,1,1,1,1,0],[1,0,1,0,1,0],[0,1,1,1,0,1],[1,0,0,0,1,1],[1,0,0,0,1,0],[1,1,1,1,1,0]]\n
[[1,1,1,1,0,1],[0,0,1,0,1,0],[1,1,1,1,1,1],[0,1,1,1,1,1],[1,1,1,0,1,0],[0,1,1,1,1,1],[1,1,0,1,1,1],[1,0,0,1,0,1],[1,1,1,1,1,1],[1,0,0,1,0,0]]\n

*/
