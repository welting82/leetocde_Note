/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 1, r = INT_MAX;
        sort(points.begin(),points.end());

        for(int i = 0; i < points.size(); i++)
        {
            r = min(r, points[i][1]);
            if(points[i][0] > r)
            {
                res++;
                r = points[i][1];
            }
        }

        return res;
    }
};
// @lc code=end
/*
[[10,16],[2,8],[1,6],[7,12]]\n
[[1,2],[2,3],[3,4],[4,5]]\n
[[1,2],[3,4],[5,6],[7,8]]\n
[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]\n
[[1,10],[3,4],[5,6]]\n
*/
