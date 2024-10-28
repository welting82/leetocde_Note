/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;
        if(n == 2) return 1;
        int l = 0, r = 1, res = 2, idx = 3;

        while(idx < n)
        {
            
            idx++;
        }
        
        return res;
    }
};
// @lc code=end

