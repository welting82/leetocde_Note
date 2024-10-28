/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for(int i = 1,j = n-2; i < n, j >-1; i++,j--)
        {
            res[i] *= (nums[i]*res[i-1]);
            res[j] *= (nums[j]*res[j+1]);
            cout<<i<<" "<<j<<" "<<res[i]<<" "<<res[j]<<endl;
        }

        return res;
    }
};
// @lc code=end

