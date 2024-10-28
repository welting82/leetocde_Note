/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int lvl = 0;

    for (string str:logs)
    {
        if(str == "../") lvl = max(0,--lvl);
        else if (str != "./") ++lvl;
    }

    return lvl;
    }
};
// @lc code=end

