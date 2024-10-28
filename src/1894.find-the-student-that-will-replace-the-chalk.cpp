/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int idx = 0, n = chalk.size();
        long long sum = 0;

        for(int i:chalk) sum += i;

        k %= sum;
        while((k -= chalk[idx]) >= 0) idx = (idx + 1) % n;

        return idx;
    }
};
// @lc code=end
/*
[3,4,1,2]\n
25\n
[5,1,5]\n
22\n
*/
