/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        int n;
        for(int i:nums)
        {
            n = res.size();
            for(int j = 0; j < n; j++)
            {
                res.push_back(res[j]);
                res.back().push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

