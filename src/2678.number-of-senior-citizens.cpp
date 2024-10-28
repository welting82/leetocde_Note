/*
 * @lc app=leetcode id=2678 lang=cpp
 *
 * [2678] Number of Senior Citizens
 */

// @lc code=start
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string info:details)
        {
            if(stoi(info.substr(11,2)) > 60) res++;
        }
        return res;
    }
};
// @lc code=end

