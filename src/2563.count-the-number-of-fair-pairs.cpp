 /*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        int low_idx, up_idx;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++)
        {
            low_idx = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            up_idx = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            res += up_idx - low_idx;
        }

        return res;
    }
};
// @lc code=end
/*
[0,1,7,4,4,5]\n
3\n
6\n
[0,1,7,4,4,5,6,3,26,7,896,3,2,5,3,5,2]\n
2\n
10\n
[1,7,9,2,5]\n
11\n
11\n
*/
