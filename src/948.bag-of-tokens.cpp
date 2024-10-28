/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int res = 0, tmp = 0, l = 0, r = tokens.size()-1;
        sort(tokens.begin(),tokens.end());

        while((power > 0 || res != 0) && l <= r)
        {
            if(power >= tokens[l])
            {
                power -= tokens[l++];
                tmp++;
            }
            else if(tmp > 0)
            {
                power += tokens[r--];
                tmp--;
            }
            else break;
            res = max(res,tmp);
        }
        return res;
    }
};
// @lc code=end
/*
[1,1,1,1,1,2,3,4,5,6,7,8]\n
1\n
[1,1,1,1,1,2,3,1,1,1,1,1,1,1,1]\n
10\n
[1,1,1,1,1,2,3,1,1,1,1,1,1,1,1]\n
1\n
[100,200]\n
150\n
[100,200,300,400]\n
200\n
[]\n
0\n
[100]\n
0\n
*/
