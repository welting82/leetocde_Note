/*
 * @lc app=leetcode id=2554 lang=cpp
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt = 0, sum = 0;
        unordered_set<int> uset(banned.begin(), banned.end());

        for(int i = 1; i <= n; i++)
        {
            if(uset.find(i) == uset.end())
            {
                if(sum + i <= maxSum) cnt++, sum += i;
                else break;
            }
        }
        return cnt;
    }
};
// @lc code=end
/*
[1,6,5]\n
5\n
6\n
[1,2,3,4,5,6,7]\n
8\n
1\n
[11]\n
7\n
50\n
*/
