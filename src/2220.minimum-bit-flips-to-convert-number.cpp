/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int tmp = start ^ goal;
        int res = 0;
        while(tmp)
        {
            res += tmp & 1;
            tmp = tmp>>1;
        }
        return res;
    }
};
// @lc code=end
/*
10\n
7\n
3\n
4\n
0\n
2\n
0\n
0\n
*/
