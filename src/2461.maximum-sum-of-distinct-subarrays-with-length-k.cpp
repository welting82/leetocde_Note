/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 */

// @lc code=start
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, sum = 0;
        int pre = 0;

        bitset<100000> tbl(0);

        for(int i = 0 ; i < nums.size(); i++)
        {
            while(tbl[nums[i]])
            {
                sum -= nums[pre];
                tbl[nums[pre++]] = 0;
            }
            sum += nums[i],tbl[nums[i]] = 1;
            if((i - pre) + 1 > k) sum -= nums[pre],tbl[nums[pre++]] = 0;
            if((i - pre) + 1 == k) res = max(res,sum);
        }

        return res;
    }
};
// @lc code=end
/*
[1,5,4,2,9,9,9]\n
3\n
[4,4,4]\n
3\n
*/
