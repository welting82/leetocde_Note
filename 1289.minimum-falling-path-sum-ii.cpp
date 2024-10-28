/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        vector<int> dp;
        dp = grid[0];

        for (int  i = 1; i < grid.size(); i++)
        {
            for (int  j = 0; j < grid[0].size(); j++)
            {
                for (int  k = 0; k < dp.size(); k++)
                {
                    if(j == k) continue;
                    else
                    {
                        cout<<dp[k]<<" "<<k<<" "<<grid[i][j]<<endl;
                        if(j == 0) dp[k] += grid[i][j];
                        else dp[k] = min(dp[k], dp[k] + grid[i][j]);
                    }
                }
            }
        }

        for(int i:dp) res = min(res, i);
        return res;

    }
};
// @lc code=end

