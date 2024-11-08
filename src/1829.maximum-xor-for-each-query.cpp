/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxBit) {
        int sum = 0, n = nums.size();
        vector<int> res(n);

        for(int i:nums) sum ^= i;
        for(int i = n - 1; i >= 0; i--)
        {
            res[(n - 1) - i] = sum ^ ((1<<maxBit) - 1);
            sum ^= nums[i];
        }

        return res;
    }
};
// @lc code=end
/*
[0,1,1,3]\n
2\n
[2,3,4,7]\n
3\n
[0,1,2,2,5,7]\n
3\n
[2,3,4,7]\n
3\n
*/
