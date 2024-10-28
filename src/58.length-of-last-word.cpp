/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, idx = s.size() - 1;

        while(idx > -1)
        {
            if(s[idx--] == ' ')
            {
                if(res == 0) continue;
                else break;
            }
            else res++;
        }
        return res;
    }
};
// @lc code=end
/*
"   fly me   to   the moon  "\n
"luffy is still joyboy"\n
*/
