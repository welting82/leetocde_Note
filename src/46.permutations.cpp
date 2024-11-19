/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int idx)
    {
        vector<int> tmp;
        if(idx == nums.size()) res.push_back(nums);
        else
        {
            for (int i = idx; i < nums.size(); i++)
            {
                tmp = nums;
                swap(tmp[idx], tmp[i]);
                dfs(tmp, idx + 1);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return res;
    }
};
// @lc code=end
/*
[1,2,3,4]
*/
