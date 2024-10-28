/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution {
public:
    int minDifference(vector<int>& nums) {
	int n = nums.size();
	// for 1 <= n <= 4 we can always change all the numbers to equal numbers
	if(n < 5)
		return 0;
	
	// first 4 elements
	partial_sort(nums.begin(), nums.begin() + 4, nums.end());
	// last 4 elements
    partial_sort(nums.rbegin(), nums.rbegin() + 4, nums.rend(), greater<int>());
	
	int min_diff = INT_MAX;
	for(int i = 0, j = n - 4; i < 4; ++i, ++j)
		min_diff = min(min_diff, nums[j] - nums[i]);
        
	return min_diff;
}
};
// @lc code=end
/*
[5,3,2,4]\n
[1,5,0,10,14]\n
[1,5,6,14,15]\n
*/
