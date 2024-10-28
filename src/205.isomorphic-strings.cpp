/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> umap_s;
        unordered_map<char,char> umap_ts;

        for(int i = 0; i < s.size(); i++)
        {
            
            if(!umap_s[s[i]]) umap_s[s[i]] = t[i];
            if(!umap_ts[t[i]]) umap_ts[t[i]] = s[i];
            if(umap_s[s[i]] != t[i] || umap_ts[t[i]] != s[i]) return false;
        }
        return true;
    }
};
// @lc code=end
/*
"egg"\n
"add"\n
"foo"\n
"bar"\n
"paper"\n
"title"\n
"badc"\n
"baba"\n
"baba"\n
"badc"\n
*/
