/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> tbl(n, vector<int> (n,0));
        int idx = 0, path_sum = INT_MAX, path_cnt = 0;

        for(auto i:edges) tbl[i[0]][i[1]] = tbl[i[1]][i[0]] = i[2];

        for(int i = 0; i < n; i++)
        {
            path_cnt = findPath(tbl, );
            if(path_cnt >= path_sum) idx = i, path_sum = path_cnt;
        }
        return idx;
    }
};
// @lc code=end

