/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = INT_MIN, _max = values[0];
        
        for(int i = 1; i < values.size(); i++)
        {
            res = max(res, _max + values[i] - i);
            _max = max(_max, values[i] + i);
        }
        return res;
    }
};
// @lc code=end
/*
[9,7,6,7,6,9]\n
[8,1,5,2,6]\n
[8,1,5,2,20]\n
[8,1,50,2,6]\n
[8,1,50,100,2,6]\n
[80,1,20,100,2,6]\n
[80,1,20,40,2,60]\n
[1,2]\n
*/
