/*
 * @lc app=leetcode id=2779 lang=cpp
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res = 0, str_idx = -1, up = INT_MIN;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] - k > up)
            {
                str_idx++;
                up = nums[str_idx] + k;
            }
            res = max(res, i - str_idx + 1);
        }

        return res;
    }
};
// @lc code=end
/*
[4,6,1,2]\n
2\n
[4,6,1,2]\n
1\n
[4,6,1,3]\n
2\n
[12,71]\n
10\n
[1,1,1,5,5]\n
0\n
[48,93,96,19]\n
24\n
*/
