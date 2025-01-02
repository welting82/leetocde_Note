/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
class Solution {
public:
    int chkVowel(string str)
    {
        bool flag = false;
        if ((str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u') &&
            (str.back() == 'a' ||  str.back() == 'e' || str.back() == 'i' || str.back() == 'o' || str.back() == 'u'))
        {
            flag = true;
        }
        return (flag)?1:0;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        vector<int> tbl(words.size() + 1, 0);

        for(int i = 0; i < words.size(); i++) tbl[i + 1] = tbl[i] + chkVowel(words[i]);
        for(int j = 0; j < queries.size(); j++)
        {
            res[j] = tbl[queries[j][1] + 1] - tbl[queries[j][0]];
        }
        return res;
    }
};
// @lc code=end
/*
["a","e","i"]\n
[[0,2],[0,1],[2,2]]\n
*/

