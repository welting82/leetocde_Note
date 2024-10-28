/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> tbl(3,0);
        int idx = 0;

        for(int i:nums)tbl[i]++;
        for(int i = 0; i < tbl.size(); i++)
        {
            while(tbl[i]-- > 0) nums[idx++] = i;
        }
        return;
    }
};
// @lc code=end
/*
[2,0,1]\n
*/
