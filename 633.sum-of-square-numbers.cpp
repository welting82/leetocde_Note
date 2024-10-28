/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 3) return true;
        long l = 0, r = sqrt(c);

        while (l <= r)
        {
            if(l*l + r*r > (long) c) r--;
            else if(l*l + r*r < (long) c) l++;
            else return true;
        }
        
        return false;
    }
};
// @lc code=end
/*
0\n
1\n
2\n
3\n
4\n
5\n
6\n
10000\n
2147483647\n
2147483645\n
*/
