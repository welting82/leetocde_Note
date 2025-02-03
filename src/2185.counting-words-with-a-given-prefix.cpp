/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;

        for(auto str:words)
        {
            if(str.size() >= pref.size())
            {
                if(str.substr(0, pref.size()) == pref) res++;
            }
        }

        return res;
    }
};
// @lc code=end

