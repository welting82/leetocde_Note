/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> vec;
        int curr = 0;

        for(auto i:trips)
        {
            vec.push_back({i[1], i[0]});
            vec.push_back({i[2], -i[0]});
        }
        sort(vec.begin(), vec.end());

        for(auto i:vec)
        {
            curr += i.second;
            if(curr > capacity) return false;
        }
        return true;
    }
};
// @lc code=end
/*
[[2,1,5],[3,3,7]]\n
4\n
[[2,4,5],[3,3,7]]\n
5\n
[[2,1,2],[3,2,3],[3,3,7]]\n
3\n
[[2,1,3],[2,1,3],[3,3,7]]\n
4\n
*/
