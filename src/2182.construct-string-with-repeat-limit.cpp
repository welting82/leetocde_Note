/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 */

// @lc code=start
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        map<char,int, greater<int>> m;
        pair<char,int> pre;

        for(auto ch:s) m[ch]++;

        for(auto i:m)
        {
            while(pre.second > 0 && i.second > 0)
            {
                res += i.first, i.second--;
                for(int j = 0; j < min(pre.second,repeatLimit); j++) res += pre.first;
                pre.second -= repeatLimit;
            }
            for(int j = 0; j < min(i.second,repeatLimit); j++) res += i.first;
            if(i.second > repeatLimit) pre = {i.first, i.second - repeatLimit};
        }

        if(pre.second > 0 && res.back() != pre.first)
        {
            for(int j = 0; j < min(pre.second,repeatLimit); j++) res += pre.first;
        }

        return res;
    }
};
// @lc code=end
/*
"cczazcc"\n
3\n
"aababab"\n
2\n
"a"\n
1\n
"abababababaaaaa"\n
2\n
"abababacccddddeeeefkefkfkfkfkfkfckdskcdkfckdkdcjmaskscbabaaaaa"\n
2\n
"afecvcvffaccvcccccccccccccccccccccccccccccccwvcv"\n
10\n
*/
