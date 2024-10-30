/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> dp(n,1);

        for(int i = 1; i < n; i++)
        {
            dp[i] = min(dp[t2] * 2, min(dp[t3] * 3, dp[t5] * 5));
            if(dp[i] == dp[t2] * 2) t2++;
            if(dp[i] == dp[t3] * 3) t3++;
            if(dp[i] == dp[t5] * 5) t5++;
        }

        return dp[n-1];
    }
};
// @lc code=end
/*
10\n
1\n
5\n
1690\n
*/