/*
 * @lc app=leetcode id=3016 lang=cpp
 *
 * [3016] Minimum Number of Pushes to Type Word II
 */

// @lc code=start
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> tbl(26,0);
        int cnt = 8, res = 0;
        for(int i:word) tbl[i-'a']++;
        sort(tbl.begin(),tbl.end(),greater());
        for(auto i:tbl)
        {
            if(i == 0) break;
            res += (cnt++/8*i);
        }
        return res;
    }
};
// @lc code=end
/*
"abcde"\n
"xyzxyzxyzxyz"\n
"aabbccddeeffgghhiiiiii"\n
"aabbccddeeffgghhiiiiiillleeeeeeeeggggggmmmmmmmmmqqqqqqqqqqmmyurieowdfjkalfjdasklfjdsakl"\n
*/
