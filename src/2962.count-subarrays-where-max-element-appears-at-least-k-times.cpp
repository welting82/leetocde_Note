/*
 * @lc app=leetcode id=2962 lang=cpp
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        
        int maxe=*max_element(nums.begin(), nums.end());
        
        long long ans=0;
        
        int count=0; // keep track of count of maxElement in [i,j]
        int i=0, j=0;
        while(j<n){
            count += (nums[j] == maxe);
            
            while(i<=j && count>=k){
                ans += (n-j);
                
                count -= (nums[i] == maxe); // shrink window
                i++;
            }
            j++;
        }
        
        return ans;
    }
};
// @lc code=end
