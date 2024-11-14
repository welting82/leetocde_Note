/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> umap;
        string tmp;

        for(string str:strs)
        {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(str);
        }

        for(auto i:umap) res.push_back(i.second);

        return res;
    }
};
// @lc code=end

