/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
class Solution {
public:
    string makeFancyString(string s) {
        int idx = 0, cnt = 0;

        for(char ch:s)
        {
            cnt = (ch == s[max(0,idx-1)])?cnt+1:1;
            if(cnt < 3) s[idx++] = ch;
        }
        s.resize(idx);
        return s;
    }
};
// @lc code=end
/*
"aaabaaaa"\n
"aaabbbbaaaaaaccccdccccceeeegfdswewvweveeweeeewffwwwwww"\n
"leeetcode"\n
"aab"\n
*/
