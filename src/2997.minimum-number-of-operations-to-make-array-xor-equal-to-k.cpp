/*
 * @lc app=leetcode id=2997 lang=cpp
 *
 * [2997] Minimum Number of Operations to Make Array XOR Equal to K
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = k;
        for (int i:nums) res ^= i;
        return __builtin_popcount(res);
    }
};
// @lc code=end
/*
[2,1,10,5,20]\n
4\n
[2,0,2,0]\n
0\n
*/
