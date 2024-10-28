/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;

        for (int i:arr)
        {
            if(i & 1) cnt++;
            else cnt = 0;
            if(cnt >= 3) return true;
        }
        return false;
    }
};
// @lc code=end
/*
[2,6,4,1]\n
[1,2,34,3,4,5,7,23,12]\n
[1,1,1]\n
*/
