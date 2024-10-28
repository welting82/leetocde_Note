/*
 * @lc app=leetcode id=1750 lang=cpp
 *
 * [1750] Minimum Length of String After Deleting Similar Ends
 */

// @lc code=start
class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size()-1;

        while(l < r)
        {
            if(s[l] == s[r])
            {
                l++,r--;
                while(l < s.size() && s[l] == s[l-1]) l++;
                while(r > 0 && s[r] == s[r+1]) r--;
            }
            else break;
        }
        return max(0,r - l + 1);
    }
};
// @lc code=end
/*
"ca"\n
"aabccabba"\n
"cabaabac"\n
"aaabbbcccbba"\n
"aaaaaaa"\n
"abcabcabcabcabcabcabc"\n
"ababababababa"\n
"abcabcabcabcabcabca"\n
"aba"\n
"bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb"\n
*/
