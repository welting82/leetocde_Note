/*
 * @lc app=leetcode id=2441 lang=cpp
 *
 * [2441] Largest Positive Integer That Exists With Its Negative
 */

// @lc code=start
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        sort(nums.begin(),nums.end());
        while (l < r)
        {
            if((nums[l] + nums[r]) == 0) return nums[r];
            else if((nums[l] + nums[r]) < 0) l++;
            else r--;
        }
        
        return -1;
    }
};
// @lc code=end
/*
[-9,-43,24,-23,-16,-30,-38,-30]\n
[-1,2,-3,3]\n
[-1,10,6,7,-7,1]\n
[-1,10,6,7,-7,1,7,-7,-7,-7,-7,2,3,4,5]\n
[-10,8,6,7,-2,-3]\n
*/
