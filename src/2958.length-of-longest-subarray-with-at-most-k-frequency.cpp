/*
 * @lc app=leetcode id=2958 lang=cpp
 *
 * [2958] Length of Longest Subarray With at Most K Frequency
 */

// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0, l = 0, r = 0;
        unordered_map<int,int> umap;

        while (r < nums.size() && l <= r)
        {
            if(++umap[nums[r]] <= k) res = max(res, r - l + 1);
            else
            {
                while(umap[nums[r]] > k) umap[nums[l++]]--;
            }
            r++;
        }
        
        return res;
    }
};
// @lc code=end
/*
[1,2,3,1,2,3,1,2]\n
2\n
[1,2,1,2,1,2,1,2]\n
1\n
[5,5,5,5,5,5,5]\n
4\n
[5,5,5,5,5,5,5]\n
1\n
[5,5,5,5,5,5,5,1,2,3,4,5,6,78,89,90]\n
3\n
[5,5,5,5,5,5,5]\n
7\n
[5]\n
1\n
[5,2]\n
1\n
[1,2,2,1,3]\n
1\n
*/
