/*
 * @lc app=leetcode id=2270 lang=cpp
 *
 * [2270] Number of Ways to Split Array
 */

// @lc code=start
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sumR = 0, sumL = 0;
        int res = 0;
        for(auto i:nums) sumR += i;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            sumL += nums[i];
            sumR -= nums[i];
            if(sumL >= sumR) res++;
        }
        return res;
    }
};
// @lc code=end
/*
[-1,-2]\n
[2,3,1,0,4,5,6,7,8,9]\n
*/
