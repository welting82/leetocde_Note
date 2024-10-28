/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0, idx;
        vector<bool> tbl(26,false);
        for(char i:allowed) tbl[i - 'a'] = true;
        
        for(string str:words)
        {
            idx = 0;
            while(idx < str.size() && tbl[str[idx] - 'a']) idx++;
            if(idx == str.size()) res++;
        }
        return res;
    }
};
// @lc code=end
/*
"ab"\n
["ad","bd","aaab","baa","badab"]\n
"abc"\n
["a","b","c","ab","ac","bc","abc"]\n
"cad"\n
["cc","acd","b","ba","bac","bad","ac","d"]\n
*/
