/*
 * @lc app=leetcode id=2370 lang=cpp
 *
 * [2370] Longest Ideal Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestIdealString(string s, int k) {
        if(k == 25) return s.size();
        vector<int> dp(s.size(),0);
        int max_length[26] = {0};
        int res = 0, idx,u,l;

        for(int i = 0; i < s.size(); i++)
        {
            idx = s[i] - 'a';
            u = min(25, idx + k);
            l = max(0, idx - k);
            for(int j = l; j <= u; j++)
            {
                dp[i] = max(dp[i], max_length[j] + 1);
            }
            max_length[idx] = max(dp[i], max_length[idx]);
        }
        for(int i:dp) res = max(res,i);
        return res;
    }
};
// @lc code=end

