/*
 * @lc app=leetcode id=1701 lang=cpp
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        int time = 0, n = cust.size();
        long tot_wait = 0;

        for (int i = 0; i < n; i++)
        {
            time = max(time, cust[i][0]) + cust[i][1];
            tot_wait += (time - cust[i][0]);
        }
        
        return (double) tot_wait / n;
    }
};
// @lc code=end
/*
[[1,2],[2,5],[4,3]]\n
[[5,2],[5,4],[10,3],[20,1]]\n
*/
