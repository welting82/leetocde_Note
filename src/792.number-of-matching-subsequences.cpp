/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0, idx, idx_s;
        unordered_map<string,int> umap;

        for(string str:words) umap[str]++;

        for(auto str:umap)
        {
            idx = idx_s = 0;
            while(idx < str.first.size() && idx_s < s.size())
            {
                if(s[idx_s] == str.first[idx]) idx++;
                idx_s++;
            }
            if(idx == str.first.size()) res += str.second;
        }
        return res;
    }
};
// @lc code=end
/*
"abcde"\n
["a","bb","acd","ace"]\n
"abcdaefabcfdgghrwcsdvgbrtfgcsdgwghijklmanop"\n
["a","bb","acd","ace","aaaa","acdffde","agfgsfgewce","acvdasevace"]\n
"dsahjpjauf"\n
["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]\n
*/
