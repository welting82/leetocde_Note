/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        vector<bool> tbl(100,false);
        int res = 0;

        for(int i:s)
        {
            if(!tbl[i-'A']) res += 2;
            tbl[i = 'A'] = !tbl[i = 'A'];
        }
        
        for(bool i:tbl)
        {
            if(i)
            {
                res++;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

