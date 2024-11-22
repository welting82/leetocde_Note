/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        if(mat.size() == 1) return 1;
        else if(mat[0].size() == 1) return mat.size();
        unordered_map<string,int> umap;
        string str;
        int res = 0;
        bool flip = false;

        for(auto i:mat)
        {
            if(i[0] == 1) flip = true;
            for(auto j:i) str += to_string((flip)? !j: j);
            umap[str]++;
            res = max(res, umap[str]);
            str.clear(), flip = false;
        }
        return res;
    }
};
// @lc code=end

