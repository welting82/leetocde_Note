/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> tbl;
    int numTrees(int n) {
        tbl.resize(max(3,n + 1),0);
        tbl[0] = tbl[1] = 1, tbl[2] = 2;

        for(int i = 3;i <= n; i++)
        {
            for(int j = 0; j < i; j++) tbl[i] += (tbl[j] * tbl[(i - 1) - j]);
        }

        return tbl[n];
    }
};
// @lc code=end
/*
1\n
3\n
4\n
5\n
19\n
*/
