/*
 * @lc app=leetcode id=2109 lang=cpp
 *
 * [2109] Adding Spaces to a String
 */

// @lc code=start
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int idx = 0;

        for(int i:spaces)
        {
            while(idx < i)
            {
                res += s[idx++];
            }
            res += " ";
        }
        res += s.substr(idx);
        return res;
    }
};
// @lc code=end

