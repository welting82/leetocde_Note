/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), idx;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        for(int i = 0; i < n; i++)
        {
            idx = i + 1;
            while(idx < n && idx <= i + nums[i])
            {
                dp[idx] = min(dp[i] + 1, dp[idx]);
                if(idx >= n - 1) break;
                idx++;
            }
        }
        return dp.back();
    }
};
// @lc code=end
/*
[2,3,0,1,4]\n
[4]\n
*/
