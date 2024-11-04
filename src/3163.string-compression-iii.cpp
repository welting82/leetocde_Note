/*
 * @lc app=leetcode id=3163 lang=cpp
 *
 * [3163] String Compression III
 */

// @lc code=start
class Solution {
public:
    string compressedString(string word) {
        string res;
        char pre = word[0];
        int cnt = 0;

        for(char ch:word)
        {
            if(cnt == 9 || ch != pre)
            {
                res += (to_string(cnt) + pre);
                pre = ch, cnt = 1;
            }
            else cnt++;
        }
        res += (to_string(cnt) + pre);
        
        return res;
    }
};
// @lc code=end
/*
"abcde"\n
"aaaaaaaaaaaaaabb"\n
*/
