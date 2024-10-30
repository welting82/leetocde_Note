/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

// @lc code=start
class Solution {
public:
    
    // problem is variation of LIS
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> inc(n), dec(n), v;
        
        // inc(n) -> it is used to store the size of increasing subsequence from "left to right" 
        // dec(n) -> it is used to store the size of increasing subsequences from "right to left", not confuse 
        // with the variable name
        
        // LIS from left to right
        for(int i = 0; i < nums.size(); i++)
        {
            if(v.empty() or nums[i] > v.back())
            {
                v.push_back(nums[i]);
                inc[i] = v.size();  // Whole code is similar to LIS problem only this new line is used for storage 
            }                       // of LIS size at every index
            else
            {
                // find the smallest number which is >= nums[i] using Binary Search
                int lo = 0, hi = v.size() - 1;
                while(lo<=hi)
                {
                    int mid = lo + (hi-lo)/2;
                    if(v[mid] >= nums[i]){
                        hi = mid - 1;
                    }
                    else
                        lo = mid + 1;
                }
                
                inc[i] = lo+1;
                v[lo] = nums[i];
            }
        }
        
        
        v.clear();
        
        // LIS from right to left
        for(int i = n - 1; i >= 0; i--)
        {
            if(v.empty() or nums[i] > v.back())
            {
                v.push_back(nums[i]);
                dec[i] = v.size();   // Whole code is similar to LIS problem only this new line is used for storage 
            }                        // of LIS size at every index
            else
            {
                // find the smallest number which is >= nums[i] using Binary Search
                int lo = 0, hi = v.size() - 1;
                while(lo<=hi)
                {
                    int mid = lo + (hi-lo)/2;
                    if(v[mid] >= nums[i]){
                        hi = mid - 1;
                    }
                    else
                        lo = mid + 1;
                }
                
                dec[i] = lo + 1;
                v[lo] = nums[i];
            }
        }
        
        // find longest increasing subsequence so that we will get minimum number of removals 
        // after subtraction from "total sequence length" 
        int mx = 0;
        
        for(int i=1; i<nums.size()-1; i++) 
        {
       
        /* e.g [2, 1, 5, 6, 3, 1]  
           LIS length from left to right = 3 (1-->5-->6)
           LIS length from right to left = 3 (6-->3-->1)
           ans = total sequence length - (LIS LToR + LIS RToL - 1(peak value counted twice so subtract it once)) 
           ans = 6 - (3 + 3 - 1) = 1
        */
            
            // minimum length of subsequence is 2 because it is guaranteed that you can make a 
            // mountain array out of nums.
            if(inc[i]>1 and dec[i]>1) 
            {
                int ans = inc[i]+dec[i]-1;
                mx = max(mx, ans);
            }
        }
        return nums.size() - mx;
    }
};
// @lc code=end
