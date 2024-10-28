/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0, tmp = -1;
        sort(nums.begin(), nums.end());
        for(int i:nums)
        {
            if(tmp >= i)
            {
                tmp ++;
                res += (tmp - i);
            }
            else tmp = i;
        }
        return res;
    }
};
// @lc code=end
/*
[1,2,2]\n
[3,2,1,2,1,7]\n
[3,1,1,1,6,7,10,8,1,1]\n
*/

