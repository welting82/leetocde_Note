/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

// @lc code=start
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quan) {
        int l = 1, mid, r = *max_element(quan.begin(), quan.end());
        int res = INT_MAX, sum = 0;

        while(l <= r)
        {
            mid = (l + r) / 2, sum = 0;
            for(int q:quan)
            {
                sum += (q / mid);
                sum += (q % mid)?1:0;
            }
            if(sum > n) l = mid + 1;
            else
            {
                res = min(res, mid);
                r = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end
/*
7\n
[15,10,10]\n
1\n
[15,10,10]\n
*/

