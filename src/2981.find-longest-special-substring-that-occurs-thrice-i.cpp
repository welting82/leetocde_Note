/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start
class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> umap;
        string str;
        int res = -1;

        for(int i = 0; i < s.size(); i++)
        {
            if(str.empty() || str.back() == s[i]) str += s[i];
            else str = s[i];
            for(int i = 1; i <= str.size(); i++) umap[str.substr(0,i)]++;
        }

        for(auto i:umap)
        {
            if(i.second >= 3) res = max(res, (int)i.first.size());
        }
        return res;
    }
};
// @lc code=end
/*
"abcdef"\n
"abcaba"\n
"aaaaaaaaaaaaaaaabcaba"\n
"aabbbbaaaabbaaaaaabbbaaacccabcabaccccdccsdcfgvwsfd"\n
*/
