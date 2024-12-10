/*
 * @lc app=leetcode id=3152 lang=cpp
 *
 * [3152] Special Array II
 */

// @lc code=start
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> res(queries.size(), false);
        vector<int> vec(nums.size(), 0);
        int idx = 0;

        for (int i = 1, j = 0; i < nums.size(); i++)
        {
            if((nums[i] + nums[i - 1]) % 2 == 0) j++;
            vec[i] = j;
        }

        for(int i = 0; i < queries.size(); i++)
        {
            if(vec[queries[i][0]] == vec[queries[i][1]]) res[i] = true;
        }

        return res;
    }
};
// @lc code=end
/*
[4,3,1,6,8]\n
[[0,2],[2,3],[2,4]]\n
[1,2]\n
[[0,0],[1,1]]\n
[4,5,2,7]\n
[[1,3]]\n
*/
