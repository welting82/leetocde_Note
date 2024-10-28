/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r_idx, int c_idx) {
        vector<vector<int>> res;
        int cnt = 1,dir_i = 0;
        pair<int,int> tgt = {r_idx,c_idx+1}, idx = {r_idx,c_idx};
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        while(res.size() != (rows*cols))
        {
            while(tgt.first != idx.first || tgt.second != idx.second)
            {
                if(idx.first >= 0 && idx.first < rows && idx.second >= 0 && idx.second < cols)
                {
                    res.push_back({idx.first,idx.second});
                }
                idx.first += (dir[dir_i].first);
                idx.second += (dir[dir_i].second);
            }

            dir_i = (dir_i < 3)?dir_i+1:0;
            if(dir_i%2 == 0) cnt++;
            tgt.first += (dir[dir_i].first*cnt);
            tgt.second += (dir[dir_i].second*cnt);
        }
        return res;
    }
};
// @lc code=end
/*
1\n
4\n
0\n
0\n

5\n
6\n
1\n
4\n
*/
